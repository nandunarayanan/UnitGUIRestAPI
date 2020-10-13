#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTesting/TestRunner/src

echo "==============Execution of the Binary=================="
./Gtest_Exec BotTestCase.csv --gtest_output="xml:ReportFromLinuxGtestBot.xml" --gtest_filter=-API*

echo jenkins | sudo -S cp ReportFromLinuxGtestBot.xml /var/lib/jenkins/workspace/UnitGUIRestfulAPI_Test/

echo "===============================Completed========================"
