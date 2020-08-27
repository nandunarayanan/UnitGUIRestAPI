#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTestFile/TestRunner/src

echo "===============conan install operation=================="
conan install ..
echo "=====================cmake operation===================="
cmake ..
echo "=====================make operation====================="
make
echo "==============Execution of the Binary=================="
./Gtest_Exec --gtest_output="xml:ReportFromLinuxGtest.xml"

echo "===============================Completed========================"
