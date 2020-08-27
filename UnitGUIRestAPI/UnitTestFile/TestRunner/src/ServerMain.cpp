
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

/*
TEST(AccountTest, BankAccountStartsEmpty) 
{	
	EXPECT_EQ("Sucess", s1.EvaluvateTestcase("SetBalanceBankAccount void 1000"));
	EXPECT_EQ("1000", s1.EvaluvateTestcase("GetBalanceBankAccount int"));
}
*/

TEST(CSV_Test, Example) 
{  
	s1.readCSV();
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
