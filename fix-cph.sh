#!/bin/bash
# CPH 路径修复 — git pull 后运行此脚本
cd "$(dirname "$0")" && node fix-cph.js
