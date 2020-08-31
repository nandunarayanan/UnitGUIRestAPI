#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTestFile/TestRunner/src

./Gtest_Exec ApiTestCase.csv --gtest_output="xml:ReportFromLinuxGtestApi.xml"
echo jenkins | sudo -S cp ReportFromLinuxGtestApi.xml /var/lib/jenkins/workspace/UnitGUIRestfulAPI_Test/
