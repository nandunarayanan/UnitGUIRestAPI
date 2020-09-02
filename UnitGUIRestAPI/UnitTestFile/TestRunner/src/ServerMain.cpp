
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

/*
TEST(AccountTest, BankAccountStartsEmpty) 
{	
	EXPECT_EQ("Sucess", s1.EvaluvateTestcase("SetBalanceBankAccount void 1000"));
	EXPECT_EQ("1000", s1.EvaluvateTestcase("GetBalanceBankAccount int"));
}
*/

TEST(setPatientName, Example) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setPatientName void Bob "));  
}
TEST(getPatientName, Example) 
{   
 ASSERT_EQ("Bob", s1.EvaluvateTestcase("getPatientName string "));  
}
TEST(setAge, Example) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setAge void 25 "));  
}
TEST(getAge, Example) 
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
TEST(getBatteryPercentage1, Case1) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setBatteryPercentage void 75"));  
}
TEST(getBatteryPercentage2, Case2) 
{   
 ASSERT_EQ("75.000000", s1.EvaluvateTestcase("getBatteryPercentage double "));  
}
TEST(setBatteryPercentage1, Case1) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setBatteryPercentage void 65.65"));  
}
TEST(setBatteryPercentage2, Case2) 
{   
 ASSERT_EQ("65.650000", s1.EvaluvateTestcase("getBatteryPercentage double "));  
}
TEST(setBatteryStatus, Example) 
{   
 ASSERT_EQ("Success", s1.EvaluvateTestcase("setBatteryStatus void 0 "));  
}
TEST(getBatteryStatus, Example) 
{   
 ASSERT_EQ("0", s1.EvaluvateTestcase("getBatteryStatus int "));  
}

TEST(API_Add, Example) 
{  	
	ASSERT_EQ("115.000000", s1.EvaluvateTestcase("add double 100 15"));		
}

TEST(API_Subtract, Example) 
{  	
	ASSERT_EQ("115.000000", s1.EvaluvateTestcase("subtract double 130 15"));		
}

TEST(API_Mul, Example) 
{  	
	ASSERT_EQ("100.000000", s1.EvaluvateTestcase("multiply double 10 10"));		
}

TEST(API_Div, Example) 
{  	
	ASSERT_EQ("8.666667", s1.EvaluvateTestcase("divide double 130 15"));
}



TEST(CSV_Test, Example) 
{  
	s1.readCSV(filename);
	for(int ab = 0; ab < s1.words.size(); ab++) 
	{
		ASSERT_EQ(s1.words1[ab], s1.EvaluvateTestcase(s1.words[ab]));
	}
	
	
}

/*
class AccountState
{
public:
	std::string intitialBalance;
	std::string withdrawAmount;
	std::string FinalBalance;
	std::string success;
};

class withdrawAccountTest : public testing::WithParamInterface<AccountState>, public testing::Test
{
public:
	withdrawAccountTest()
	{
		s1.EvaluvateTestcase("SetBalanceBankAccount void "+ GetParam().intitialBalance);
	}
};

TEST_P(withdrawAccountTest, FinalBalance)
{
	auto as = GetParam();
	auto success = s1.EvaluvateTestcase("WithdrawMoneyBankAccount bool "+as.withdrawAmount);
	EXPECT_EQ(as.FinalBalance, s1.EvaluvateTestcase("GetBalanceBankAccount int"));
	EXPECT_EQ(as.success, success);
}

INSTANTIATE_TEST_CASE_P(default, withdrawAccountTest,
	testing::Values(
		AccountState{ "100","50","50","1" },
		AccountState{ "100", "200", "100", "0" }
	)
);
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
    //std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;
    for(const char & line : md5.digest())        
        {
        	std::cout << (int(line)) <<std::endl;
        }
    //md5.digest();
    /************/
  std::thread t1(SubscriberMain, &s1);  
  std::thread t2(PublisherMain, &s1);	
    LOG_DEBUG("B4 T1 join:");
    
    testing::InitGoogleTest(&argc, argv);
    LOG_INFO("B4 Return all test;");
    //return RUN_ALL_TESTS();
	RUN_ALL_TESTS();

    LOG_INFO("B4 threads are joined");
    s1.setStopMain(true);
    LOG_INFO("B4 threads are joined");
    t1.join();
    t2.join();		
    LOG_DEBUG("Ending the main");

  return 0;
}
