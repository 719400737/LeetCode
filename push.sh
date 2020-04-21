#!/bin/sh
git add .
git commit -m"$(date +%y%m%d)"
git push origin master
