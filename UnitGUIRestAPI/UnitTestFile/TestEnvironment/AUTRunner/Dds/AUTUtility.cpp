#include "AUTUtility.h"
#include<iostream>

using namespace std;

AUTUtility::AUTUtility(): m_msg("")
			, m_Resultmsg("")
			, messageCounter(0)
			, m_stop(false)
{
}



string AUTUtility::getMsg()
{
	return m_msg;
}
    
void AUTUtility::setMsg(string msg)
{
	m_msg = msg;
	cout << "Setting setmg: "<< m_msg <<"####" <<endl;
}

string AUTUtility::getResultMsgPub()
{
      return m_Resultmsg;
}
    
void AUTUtility::setResultMsgPub(string msg)
{
      m_Resultmsg = msg;
}
