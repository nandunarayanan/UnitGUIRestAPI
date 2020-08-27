#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/squish-for-web-6.6.1/bin
export SQUISH_LICENSEKEY_DIR="/home/bastin"
echo "==============Running WEB API Application================"
./squishrunner --host 192.168.43.13 --port 4322 --testsuite /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/suite_gwt1 --reportgen xml,/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/Report/results_WebAPI.xml
