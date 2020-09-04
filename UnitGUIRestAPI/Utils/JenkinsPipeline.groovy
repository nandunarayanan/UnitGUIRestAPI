pipeline 
{
    agent any
    stages 
	{
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
                //define scm connection for polling
                git branch: 'master', credentialsId: 'nandu', url: 'https://github.com/nandunarayanan/UnitGUIRestAPI.git'
                
            
				echo "Testing for SCM event - Done"
			}
		}   
        
        stage('Checkout')
		{
            steps 
			{
				echo "************Checkout SCM repository to the Host server - IN PROGRESS***********"
				sh label: '', script: '/home/bastin/JenkinsCmd/gitPull.sh'
				echo  "************Checkout SCM repository to the Host server - DONE ****************"
			}
		}
            
         
            
        stage('Build Management Execution')
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
            
            
               
        stage('Deployment to Test Runner/Environment')
		{
            steps 
			{
				echo "************Deployment to Test Environment - IN PROGRESS ************"
				
				sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/Deployment/FileTransfer.sh'
				
				echo "************Deployment to Test Environment - DONE************"
			}
		}
            
		stage('Sonarqube-AUT Static Code Analysing')
		{
			steps 
			{
				echo "************Sonarqube-AUT Static Code Analysing - IN PROGRESS ************"
				
				//sh label: '', script: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/Deployment/FileTransfer.sh'
				
				echo "************Sonarqube-AUT Static Code Analysing - DONE************"
			}
		}
            
		stage('Execution [class Level]')
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
            
		stage('Sonarqube- Class Level Testing Coverage')
		{
			steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            
		stage('Execution  [API]')
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
            
            
		stage('Sonarqube- API Level Testing Coverage')
		{
			steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            
            
		stage('Execution [Squish Desktop]')
		{
            steps 
			{
				echo "************Squish Desktop from the [Host Server] - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '30791', squishPackageName: 'Default', testSuite: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/GUITesting/suite_gwt1'])
				squish([host: 'localhost', port: '4322', squishPackageName: 'Squish_QT', testSuite: '/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/DesktopGUI/suite_js'])
				echo "************Squish Desktop from the [Host Server] - DONE************"
			}
		}
            
		stage('Sonarqube- Desktop GUI Testing Coverage')
		{
            steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            
            
		stage('Execution [Squish Web]')
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
            
            
		stage('Sonarqube- Web GUI Testing Coverage')
		{
            steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            
		stage('Execution [Squish Restful API]')
		{
			steps 
			{
				echo "************Squish from the [Host Server] - IN PROGRESS************"
				squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Squish from the [Host Server] - DONE************"
			}
		}
            
		stage('Sonarqube- Restful API Testing Coverage')
		{
            steps 
			{
				echo "************Sonarqube Coverage Reporting - IN PROGRESS************"
				//squish([host: 'proxy60.rt3.io', port: '36113', squishPackageName: 'Default', testSuite: 'home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/RestfulTesting/TestSuite/suite_Ex_bdd_suite2'])
				echo "************Sonarqube Coverage Reporting- DONE************"
			}
		}
            
    }
        
	post 
	{
		always 
		{
			echo "************Publishing Google test result from child node1 - IN PROGRESS************"
			xunit([GoogleTest(deleteOutputFiles: true, failIfNotNew: true, pattern: '*.xml', skipNoTestFiles: false, stopProcessingIfError: true)])
			echo "************Publishing Google test result from child node1 - Done************"
		}
	}
}
