
 /**
 * File Name    	: ServerMain.cpp
 *  
 * Description  	: This source file contains the testcases and main function
 *
 * Modifiled Date	: 22/09/2020
 *
 */

#include <iostream>
#include <thread>

#include <gtest/gtest.h>

#include "DataPacketPubSubTypes.h"
#include "ServerUtility.h"

#include <fastrtps/Domain.h>
#include <fastrtps/log/Log.h>

#include "optionparser.h"
#include "Logger.h"
#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include "Poco/DigestEngine.h"

using namespace CPlusPlusLogging;

using namespace eprosima;
using namespace fastrtps;
using namespace rtps;

ServerUtility s1;
std::string filename = "BotTestCase.csv";

/* Following are the test cases for direct execution.*/

TEST(setPatientName, setPatientName) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setPatientName void Bob "));  
}
TEST(getPatientName, getPatientName) 
{   
 ASSERT_EQ("Bob", s1.EvaluvateTestcase("getPatientName string "));  
}
TEST(setAge, setAge) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setAge void 25 "));  
}
TEST(getAge, getAge) 
{   
 ASSERT_EQ("25", s1.EvaluvateTestcase("getAge long "));  
}
TEST(setGender, Example) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setGender void M "));  
}
TEST(getGender, Example) 
{   
 ASSERT_EQ("M", s1.EvaluvateTestcase("getGender char "));  
}
TEST(setBatteryPercentage75, setBatteryPercentage75) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setBatteryPercentage void 75"));  
}
TEST(getBatteryPercentage75, getBatteryPercentage75) 
{   
 ASSERT_EQ("75.000000", s1.EvaluvateTestcase("getBatteryPercentage double "));  
}
TEST(setBatteryPercentage65, setBatteryPercentage65) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setBatteryPercentage void 65.65"));  
}
TEST(getBatteryPercentage65, getBatteryPercentage65) 
{   
 ASSERT_EQ("65.650000", s1.EvaluvateTestcase("getBatteryPercentage double "));  
}
TEST(setBatteryStatus, setBatteryStatus) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setBatteryStatus void 0 "));  
}
TEST(getBatteryStatus, Example) 
{   
 ASSERT_EQ("0", s1.EvaluvateTestcase("getBatteryStatus int "));  
}

/*Test cases for API execution*/
TEST(API_PatientAdd, API_PatientAdd) 
{  	
	ASSERT_EQ("115.000000", s1.EvaluvateTestcase("add double 100 15"));		
}


TEST(API_PatientRemove, API_PatientRemove) 
{  	
	ASSERT_EQ("115.000000", s1.EvaluvateTestcase("subtract double 130 15"));		
}


/*Test cases for CSV test cases */
TEST(CSV_Test, CSV_Test) 
{  
	s1.readCSV(filename);
	for(int ab = 0; ab < s1.words.size(); ab++) 
	{
		ASSERT_EQ(s1.words1[ab], s1.EvaluvateTestcase(s1.words[ab]));
	}
}

 /** 
  * 
  *Function Name : main
  *
  * Description  : This is the main function of the Test Runner.
  * 		   In this function a sample conan execution is showcased.
  * 		   Similarly to showcase the working of Eprosima DDS in 2 
  * 		   threads; one for the publisher and other for the subscriber
  * 		   At the end both will join if every process is successfully 
  * 		   completed				   
  * 
  * Parameters   : Testcase filename (*.csv)
  * 
  * Return Value : integear (if all test cases are passed '0' else '1')
  *		    This is to skip the futher steps in jenkins if any failure
  * 		    in the google test
  * 
  * 
  */
int main(int argc, char **argv) 
{
    if(1 == argc)
    {
		filename = argv[1];
    }
    /*****************/
    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();
    for(const char & line : md5.digest())        
    {
	    std::cout << (int(line)) <<std::endl;
    }
    /************/
    std::thread t1(SubscriberMain, &s1);  
    std::thread t2(PublisherMain, &s1);	
    LOG_DEBUG("B4 T1 join:");

    testing::InitGoogleTest(&argc, argv);
    LOG_INFO("B4 Return all test;");
    int retVal = RUN_ALL_TESTS();

    LOG_INFO("B4 threads are joined");
    s1.setStopMain(true);
    LOG_INFO("B4 threads are joined");
    t1.join();
    t2.join();		
    LOG_DEBUG("Ending the main");
    std::cout << "retVal = " << retVal <<std::endl;
    return retVal;
}
