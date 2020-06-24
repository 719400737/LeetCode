#!/bin/sh
#删除所有名字不是cpp的文件
find . ! -name "*.cpp"  ! -name "*.sh"  ! -name "*.json"  -type f | xargs rm