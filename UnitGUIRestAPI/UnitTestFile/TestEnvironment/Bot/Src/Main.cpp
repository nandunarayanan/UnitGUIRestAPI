#include <iostream>
#include <thread>
#include "Application/Patient.h"
#include "Application/Battery.h"
#include "Bot/Bot.h"
#include "Dds/DataPacketPubSubTypes.h"
#include "Dds/AUTUtility.h"

int main()
{
	Bot bot;
	std::cout << "Result for getPatientName: " << bot.RunUnitTest("getPatientName int") << std::endl;
	std::cout << "Result for add double 10 20: " << bot.RunUnitTest("add double 10 20") << std::endl;
	std::cout << "Result for subtract double 10 20: " << bot.RunUnitTest("subtract double 10 20") << std::endl;
	std::cout << "Result for setBatteryPercentage void 75: " << bot.RunUnitTest("setBatteryPercentage void 75") << std::endl;
	std::cout << "Result for Wrong Function: " << bot.RunUnitTest("Wrong Function") << std::endl;	
	
	AUTUtility Aut;
	std::thread t1(SubscriberMain, &Aut);  
	std::thread t2(PublisherMain, &Aut);	


	while(1)
	{
		if(Aut.getMsg()!= "")
		{	std::string result = bot.RunUnitTest(Aut.getMsg());	
			Aut.setResultMsgPub(result);
			Aut.setMsg("");
		}
	}

	std::cout << "B4 T1 join"<<std::endl;
	t1.join();
	std::cout << "B4 T2 join"<<std::endl;
	std::cout <<Aut.getMsg() <<std::endl;

	t2.join();	
	std::cout << "After T2 join"<<std::endl;

	return 0;
}
