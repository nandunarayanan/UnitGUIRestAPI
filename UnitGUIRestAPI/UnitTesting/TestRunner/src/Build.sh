#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTesting/TestRunner/src

echo "===============conan install operation=================="
conan install ..
echo "=====================cmake operation===================="
cmake ..
echo "=====================make operation====================="
make
