#! /bin/bash

echo "======================Setting PWD========================"
cd /home/pi/TestEnvironment/BOT/
echo "=====================cmake operation===================="
cmake CMakeLists.txt
echo "=====================make operation====================="
make clean all
echo "==============Execution of the Binary=================="
./Bot
echo "===============================Completed========================"
