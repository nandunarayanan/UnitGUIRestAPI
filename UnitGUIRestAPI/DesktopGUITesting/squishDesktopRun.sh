#! /bin/bash

echo "======================Setting PWD========================"
cd /home/bastin/squish-for-web-6.6.1/bin
export SQUISH_LICENSEKEY_DIR="/home/bastin"
echo "==============Running REST API Application================"
./squishrunner --host proxy61.rt3.io --port 38986 --testsuite /home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/DesktopGUITesting/suite_js --reportgen xmljunit,/var/lib/jenkins/workspace/UnitGUIRestfulAPI_Test/results_Desktop.xml
