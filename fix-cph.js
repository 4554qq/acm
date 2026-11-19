const fs = require('fs');
const path = require('path');
const crypto = require('crypto');

function md5(str) {
    return crypto.createHash('md5').update(str).digest('hex');
}

// 认这些扩展名是"源文件"，.md/.txt 之类不算
const CODE_EXT = new Set(['.cpp', '.c', '.cc', '.cxx', '.c++',
                          '.py', '.java', '.rs', '.go', '.js', '.ts', '.inl']);

// 找所有包含 .cph 子目录的题目目录
function findProblemDirs(root) {
    const out = [];
    (function walk(dir) {
        let entries;
        try { entries = fs.readdirSync(dir, { withFileTypes: true }); }
        catch { return; }
        for (const e of entries) {
            if (e.name.startsWith('.git')) continue;
            const full = path.join(dir, e.name);
            if (e.isDirectory()) {
                if (e.name === '.cph') out.push(path.dirname(full));
                else walk(full);
            }
        }
    })(root);
    return out;
}

const root = __dirname;
console.log('🔧 扫描仓库:', root, '\n');

const problemDirs = findProblemDirs(root);
let fixed = 0, renamed = 0, ambiguous = 0;

for (const dir of problemDirs) {
    const cphDir = path.join(dir, '.cph');
    const relDir = path.relative(root, dir);

    // 目录里所有源文件
    const sourceFiles = fs.readdirSync(dir).filter(name => {
        const p = path.join(dir, name);
        try { return fs.statSync(p).isFile() && CODE_EXT.has(path.extname(name).toLowerCase()); }
        catch { return false; }
    });

    // 目录里所有 .prob
    const probFiles = fs.readdirSync(cphDir)
        .filter(n => n.endsWith('.prob'))
        .map(n => path.join(cphDir, n));

    // 第一轮：按 .prob 文件名里的"声称源文件名"直接匹配
    const claimed = new Set();
    const pairs = [];
    const orphans = [];
    for (const probPath of probFiles) {
        let base = path.basename(probPath).slice(1).replace(/\.prob$/, '');
        const m = base.match(/^(.+)_([0-9a-f]{32})$/);
        const claimedName = m ? m[1] : base;
        if (sourceFiles.includes(claimedName)) {
            pairs.push({ probPath, srcName: claimedName, renamed: false });
            claimed.add(claimedName);
        } else {
            orphans.push({ probPath, claimedName });
        }
    }

    // 第二轮：孤儿 .prob 尝试一对一配对给未认领的源文件（改名场景）
    const unclaimed = sourceFiles.filter(s => !claimed.has(s));
    if (orphans.length === 1 && unclaimed.length === 1) {
        const p = orphans[0];
        console.log(`  ↻ 改名配对 [${relDir}]`);
        console.log(`      旧 prob 声称: ${p.claimedName}`);
        console.log(`      配对到源文件: ${unclaimed[0]}`);
        pairs.push({ probPath: p.probPath, srcName: unclaimed[0], renamed: true });
        claimed.add(unclaimed[0]);
    } else if (orphans.length > 0) {
        console.log(`  ⚠ 有歧义未动 [${relDir}]`);
        for (const o of orphans) console.log(`      孤儿 prob: ${path.basename(o.probPath)} (声称 ${o.claimedName})`);
        for (const s of unclaimed) console.log(`      未认领源文件: ${s}`);
        ambiguous += orphans.length;
    }

    // 第三轮：对齐哈希
    for (const pair of pairs) {
        const correctPath = path.join(dir, pair.srcName);
        const hashInput = correctPath.replace(/\//g, '\\').replace(/^[A-Z]:/, s => s.toLowerCase());
        const newHash = md5(hashInput);

        const data = JSON.parse(fs.readFileSync(pair.probPath, 'utf-8'));
        data.srcPath = hashInput;

        const newBase = '.' + pair.srcName + '_' + newHash + '.prob';
        const newProbPath = path.join(cphDir, newBase);

        if (pair.probPath !== newProbPath) {
            fs.writeFileSync(pair.probPath, JSON.stringify(data));
            fs.renameSync(pair.probPath, newProbPath);
            console.log(`  ✓ ${pair.srcName}  ${pair.renamed ? '(改名+对齐)' : '(对齐)'}`);
            renamed++;
        } else {
            fs.writeFileSync(pair.probPath, JSON.stringify(data));
            console.log(`  ✓ ${pair.srcName}  (哈希已匹配)`);
        }
        fixed++;
    }
}

console.log(`\n✅ 完成: 处理 ${fixed} 个 .prob, 重命名 ${renamed} 个, 歧义待手动 ${ambiguous} 个`);
