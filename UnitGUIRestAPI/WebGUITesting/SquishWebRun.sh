#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/squish-for-web-6.6.1/bin
export SQUISH_LICENSEKEY_DIR="/home/bastin"
echo "==============Running WEB API Application================"
./squishrunner --host proxy61.rt3.io --port 36793 --testsuite /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/suite_gwt1
