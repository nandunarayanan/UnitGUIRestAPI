#include <thread>
#include <string>
#include <algorithm>
#include "ServerUtility.h"
#include "Logger.h"

using namespace CPlusPlusLogging;

string ServerUtility::getMsg()
{
      return m_msgRecived;
}
    
void ServerUtility::setMsg(string msg)
{
      m_msgRecived = msg;
}

string ServerUtility::getMsgPublish()
{
      return m_msgPublish;
}
    
void ServerUtility::setMsgPublish(string msg)
{
      m_msgPublish = msg;
}

string ServerUtility::EvaluvateTestcase(string msg)
{
	setMsgPublish(msg);
	while(getMsg() == "")
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	//int test = stoi(getMsg());
	string test = getMsg();
	setMsg("");
	return test;
}

void ServerUtility::readCSV(std::string filename)
{
    	LOG_DEBUG("Came @ CSV_Test: ");
	std::vector<std::string> vecOfStr;
        std::string tmp;
        char delim = ';'; 
	bool result = getFileContent("/home/bastin/UnitGUIRestAPI/UnitGUIRestAPI/UnitTesting/TestRunner/Testcase/" + filename, vecOfStr);
	
	if(result)
    	{
    		for(std::string & line : vecOfStr)        
        	{
		  std::string lCopy = line;
		  replace(lCopy.begin(),lCopy.end(),',',' ');
		  std::stringstream str_strm1(lCopy);
		  
	          int c=0;
          
		  while (std::getline(str_strm1, tmp, delim)) 
		   {
		   	if (c == 0)
		   	{
		   	   words.push_back(tmp);	
		   	   c++;   	
		   	}
		   	else
		   	{
		   	   //replace(tmp.begin(),tmp.end(),'\r',' ');
		   	   tmp.erase( std::remove(tmp.begin(), tmp.end(), '\r'), tmp.end() );
		   	   words1.push_back(tmp);
		   	   c = 0;
		   	}   
		   }
        	}
    	}
    	LOG_DEBUG("Reading CSV:");
    	for(int ab = 0; ab < words.size(); ab++) 
	{
		LOG_DEBUG(words[ab]+": testcase to AUT");
		LOG_DEBUG(words1[ab]+": LHS");
	}
}

bool ServerUtility::getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs)
{
    // Open the File
    std::ifstream in(fileName.c_str());
    // Check if object is valid
    if(!in)
    {
    	LOG_ERROR(fileName+" cannot open : LOG_ERROR");
        return false;
    }
    std::string str;
    // Read the next line from File untill it reaches the end.
    while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }
    //Close The File
    in.close();
    return true;
}

 
void ServerUtility::setStopMain(bool s)
{
   m_stop_main = s;
}

bool ServerUtility::getStopMain()
{
   return m_stop_main;
}
