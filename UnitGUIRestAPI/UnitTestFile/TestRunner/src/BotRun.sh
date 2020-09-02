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
./Gtest_Exec BotTestCase.csv --gtest_output="xml:ReportFromLinuxGtestBot.xml" --gtest_filter=-API

echo jenkins | sudo -S cp ReportFromLinuxGtestBot.xml /var/lib/jenkins/workspace/UnitGUIRestfulAPI_Test/

echo "===============================Completed========================"
