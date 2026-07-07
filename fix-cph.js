const fs = require('fs');
const path = require('path');
const crypto = require('crypto');

function md5(str) {
    return crypto.createHash('md5').update(str).digest('hex');
}

function walk(dir) {
    const results = [];
    const entries = fs.readdirSync(dir, { withFileTypes: true });
    for (const entry of entries) {
        const full = path.join(dir, entry.name);
        if (entry.isDirectory() && !entry.name.startsWith('.git')) {
            results.push(...walk(full));
        } else if (entry.isFile() && full.includes(path.sep + '.cph' + path.sep) && full.endsWith('.prob')) {
            results.push(full);
        }
    }
    return results;
}

const repo = __dirname;
console.log('🔧 修复 CPH 路径...');
console.log('   仓库:', repo);
console.log('');

const probFiles = walk(repo);
let count = 0;
let renamed = 0;

for (const probFile of probFiles) {
    let name = path.basename(probFile);
    name = name.slice(1);                          // 去掉开头 .
    name = name.replace(/\.prob$/, '');             // 去掉 .prob
    const match = name.match(/^(.+)_([0-9a-f]{32})$/);
    const srcFile = match ? match[1] : name;
    const oldHash = match ? match[2] : '';

    const srcDir = path.dirname(path.dirname(probFile));
    const correctPath = path.join(srcDir, srcFile);

    if (!fs.existsSync(correctPath)) {
        console.log(`  ✗ ${srcFile} (文件不存在)`);
        continue;
    }

    // CPH 的哈希算法：MD5(小写 Windows 路径 + 单反斜杠)
    const winPath = correctPath.replace(/\//g, '\\').toLowerCase();
    const newHash = md5(winPath);
    const jsonPath = correctPath.replace(/\//g, '\\');

    // 更新 prob 文件内容
    const data = JSON.parse(fs.readFileSync(probFile, 'utf-8'));
    data.srcPath = jsonPath;
    fs.writeFileSync(probFile, JSON.stringify(data, null, null));

    // 如果哈希变了，重命名文件
    if (newHash !== oldHash) {
        const newName = '.' + srcFile + '_' + newHash + '.prob';
        const newPath = path.join(path.dirname(probFile), newName);
        fs.renameSync(probFile, newPath);
        renamed++;
    }

    console.log(`  ✓ ${srcFile}`);
    count++;
}

console.log(`\n✅ 完成！共处理 ${count} 个文件`);
if (renamed > 0) {
    console.log(`   其中 ${renamed} 个文件名哈希已更新（换电脑导致）`);
}
