#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTestFile/TestRunner/src

./Gtest_Exec ApiTestCase.csv --gtest_output="xml:ReportFromLinuxGtestApi.xml"
