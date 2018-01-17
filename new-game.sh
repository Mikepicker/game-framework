#!/bin/bash
mkdir $1
cp *.cpp $1
cp Makefile $1
cp -R assets $1
cp bundle_linux.sh $1
cp bundle_win.sh $1
cd $1
grep -rl '_framework_' ./ | xargs sed -i 's/_framework_/'$2'/g'
