const fs = require('fs');
const path = require('path');
const { globSync } = require('child_process');

// 用简单的递归代替 glob
function walk(dir, pattern) {
    const results = [];
    const entries = fs.readdirSync(dir, { withFileTypes: true });
    for (const entry of entries) {
        const full = path.join(dir, entry.name);
        if (entry.isDirectory() && !entry.name.startsWith('.git')) {
            results.push(...walk(full, pattern));
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

for (const probFile of probFiles) {
    // 提取源文件名: .01背包.cpp_hash.prob → 01背包.cpp
    let name = path.basename(probFile);
    name = name.slice(1);                          // 去掉开头 .
    name = name.replace(/\.prob$/, '');             // 去掉 .prob
    // 去掉末尾的 _32位hex哈希
    const match = name.match(/^(.+)_([0-9a-f]{32})$/);
    const srcFile = match ? match[1] : name;

    const srcDir = path.dirname(path.dirname(probFile));
    const correctPath = path.join(srcDir, srcFile);

    if (!fs.existsSync(correctPath)) {
        console.log(`  ✗ ${srcFile} (文件不存在)`);
        continue;
    }

    // 转成 JSON 中的 Windows 路径: d:\\code\\acm\\...
    const jsonPath = correctPath.replace(/\//g, '\\');

    const data = JSON.parse(fs.readFileSync(probFile, 'utf-8'));
    data.srcPath = jsonPath;
    data.url = jsonPath;
    fs.writeFileSync(probFile, JSON.stringify(data, null, null));

    console.log(`  ✓ ${srcFile}`);
    count++;
}

console.log(`\n✅ 完成！共处理 ${count} 个 .prob 文件`);
