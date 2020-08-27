//! Main.cpp

#include <iostream>
#include <thread>
#include "Application/Patient.h"
#include "Application/Battery.h"
#include "Api/Api.h"
#include "Dds/DataPacketPubSubTypes.h"
#include "Dds/AUTUtility.h"

int main()
{
	Api api;
	
	AUTUtility Aut;
	std::thread t1(SubscriberMain, &Aut);  
	std::thread t2(PublisherMain, &Aut);	


	while(1)
	{
		if(Aut.getMsg()!= "")
		{	std::string result = api.Run(Aut.getMsg());	
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
