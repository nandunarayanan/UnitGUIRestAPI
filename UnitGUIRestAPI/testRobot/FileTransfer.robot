*** Settings ***
Documentation     This test case ensure that the application under test, test scripts are deployed into remote hardware
...               from the Host test server
Library           SCPLibrary
Variables		  Configuration.py

*** Test Cases ***
Transfer the file to the target test folder
    [Timeout]    10 minutes
    Open Connection    ${HOST}    port=${PORT}    username=${USERNAME}    password=${PASSWORD}
    put directory    ${HALHostPath}    ${HALDeployPath}
    Close Connection
