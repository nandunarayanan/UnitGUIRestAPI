pipeline 
{
    agent any
    stages 
	{
		/*Waiting for project github event*/
		stage('Build Trigger [SCM poll]') 
		{
		    
			steps 
			{
				echo "********Waiting for SCM event - IN PROGRESS***********"

				script 
				{
				    properties([pipelineTriggers([pollSCM('* * * * *')])])
				}
				echo "Waiting for SCM event - Done"
				git branch: 'master', credentialsId: 'nandu', url: 'https://github.com/nandunarayanan/UnitGUIRestAPI.git'
				echo "Testing for SCM event - Done"
			}
		}   
        	/*Checkout the test runner and test environment artifacts*/
		stage('Checkout')
		{
			steps 
			{
				echo "************Checkout SCM repository to the Host server - IN PROGRESS***********"
				sh label: '', script: '/home/bastin/JenkinsCmd/gitPull.sh'
				echo  "************Checkout SCM repository to the Host server - DONE ****************"
			}
		}
		/*Test automation and Product build chaining*/
		stage('Test automation and Product build chaining')
		{
			steps 
			{
				echo "************Building the Test Runner files- IN PROGRESS ************"
				
				//sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/Deployment/FileTransfer.sh'
				
				echo "************Building the Test Runner files - DONE************"
				echo "************Building the Test Environment files- IN PROGRESS ************"
				echo "************Building the Test Environment files- Done ************"
			}
		}  
		/*Deployment*/               
		stage('Deployment to Test Runner/Environment')
		{
			steps 
			{
				echo "************Deployment to Test Environment & Test Runner - IN PROGRESS ************"
				
				sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/Deployment/FileTransfer.sh'
				
				echo "************Deployment to Test Environment & Test Runner - DONE************"
			}
		}
            	/*Static code analyzing of AUT*/
		stage('Sonarqube-AUT Static Code Analysing')
		{
			steps 
			{
				echo "************Sonarqube-AUT Static Code Analysing - IN PROGRESS ************"
				
				//sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/Deployment/FileTransfer.sh'
				
				echo "************Sonarqube-AUT Static Code Analysing - DONE************"
			}
		}
            
		stage('AUT-Unit test execution [class Level]')
		{
			steps 
			{
				parallel("Execute Google Test from [Host Server]":
				{
				
					echo "************Execution of Google Test from the Host server - IN PROGRESS************"
					
					sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTesting/TestRunner/src/BotRun.sh'
					
					echo "************Execution of Google Test from the Host server - DONE************"
							
					
				},
				"Execution of BOT level Testing":
				{
						
				   
					echo "************Execution of BOT level Testing - IN PROGRESS************"
					
					sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/Deployment/ExecutionBot.sh'
					
					echo "************Execution of BOT level Testing - DONE************"
						
				
				})
			}
		}
            	/*Test coverage*/
		stage('Sonarqube- AUT Class Level Test Coverage')
		{
			steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            	/*Component level testing*/
		stage('AUT-Component test execution [API level]')
		{
			steps 
			{
				parallel("Execute Google Test from [Host Server]":
				{
				
					echo "************Execution of API level Testing in the Host server - IN PROGRESS************"
					
					sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTesting/TestRunner/src/ApiRun.sh'
					
					echo "************Execution of API level Testing in the Host server - DONE************"
						
				
				},
				"Execution of API level Testing":
				{
						
				   
					echo "************Execution of API level Testing in TestRunner - IN PROGRESS************"
					
					sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/Deployment/ExecutionApi.sh'
					
					echo "************Execution of API level Testing in TestRunner - DONE************"
						
				
				})
			}
		}
            
            	/*Test coverage*/
		stage('Sonarqube- AUT API Level Test Coverage')
		{
			steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            
            	/*Desktop GUI testing*/
		stage('Desktop AUT- GUI Testing [Squish]')
		{
			steps 
			{
				echo "************Squish Desktop from the [Host Server] - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '30791', squishPackageName: 'Default', testSuite: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/suite_gwt1'])
				squish([host: 'localhost', port: '4322', squishPackageName: 'Squish_QT', testSuite: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/DesktopGUI/suite_js'])
				echo "************Squish Desktop from the [Host Server] - DONE************"
			}
		}
            	/*Test coverage*/
		stage('Sonarqube- Desktop GUI Test Coverage')
		{
			steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            	/*Web application GUI testing*/
		stage('Web AUT- GUI Testing [Squish]')
		{
			steps 
			{
				echo "************Squish from the [Host Server] - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '30791', squishPackageName: 'Default', testSuite: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/suite_gwt1'])
				squish([host: 'proxy60.rt3.io', port: '36113', resultFolder: '/var/lib/jenkins/workspace/UnitGUIRestfulAPI_Test/squish_junit', squishPackageName: 'Default', testSuite: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/suite_gwt1'])
				/*
				archiveArtifacts artifacts: '/UnitGUIRestfulAPI_Test/squish_junit/*.xml', followSymlinks: false
				step([$class: 'ACIPluginPublisher', name: '/var/lib/jenkins/workspace/UnitGUIRestfulAPI_Test/squish_junit/*.xml', shownOnProjectPage: false])
				//squish([squishPackageName: 'Default', testSuite: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/suite_gwt1'])
				*/
				echo "************Squish from the [Host Server] - DONE************"
			}
		}
		/*Test coverage*/	
		stage('Sonarqube- Web GUI Test Coverage')
		{
			steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
		/*Web application rest api testing*/            
		stage('Web AUT- Restful API Testing [Squish]')
		{
			steps 
			{
				echo "************Squish from the [Host Server] - IN PROGRESS************"
				squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Squish from the [Host Server] - DONE************"
			}
		}
            	/*test coverage*/
		stage('Sonarqube- Restful API Test Coverage')
		{
			steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            
    	}/*End of stages*/
        
	post 
	{
		always 
		{
			echo "************Publishing xUnit result  - IN PROGRESS************"
			xunit([GoogleTest(deleteOutputFiles: true, failIfNotNew: true, pattern: '*.xml', skipNoTestFiles: false, stopProcessingIfError: true)])
			echo "************Publishing xUnit result from child node1 - Done************"
		}
	}
}
