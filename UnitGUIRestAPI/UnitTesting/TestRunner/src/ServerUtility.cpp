/**
 * File Name      : ServerUtility.cpp
 *  
 * Description    : This is the file is responsible all the utility related
		     task of the Unit & class level testing.
 *
 * Modifiled Date : 22/09/2020
 *
 */
#include <thread>
#include <string>
#include <algorithm>
#include "ServerUtility.h"
#include "Logger.h"

using namespace CPlusPlusLogging;

 /** 
  * 
  *Function Name : getMsg
  *
  * Description  : This function returns a message recieved from AUT				   
  * 
  * Parameters   : None
  * 
  * Return Value : recieved message(m_msgRecived)
  * 
  * 
  */
  
string ServerUtility::getMsg()
{
      return m_msgRecived;
}

  /** 
  * 
  *Function Name : setMsg
  *
  * Description  : This function set a message in AUT				   
  * 
  * Parameters   : msg
  * 
  * Return Value : None
  * 
  * 
  */
void ServerUtility::setMsg(string msg)
{
      m_msgRecived = msg;
}

 /** 
  * 
  *Function Name : getMsgPublish
  *
  * Description  : This function returns a publishing message to Server				   
  * 
  * Parameters   : None
  * 
  * Return Value : message to be published(m_msgPublish)
  * 
  * 
  */
string ServerUtility::getMsgPublish()
{
      return m_msgPublish;
}

 /** 
  * 
  *Function Name : setMsgPublish
  *
  * Description  : This function sets the message to be published to Server				   
  * 
  * Parameters   : message to be published(m_msgPublish)
  * 
  * Return Value : None
  * 
  * 
  */
void ServerUtility::setMsgPublish(string msg)
{
      m_msgPublish = msg;
}



 /** 
  * 
  *Function Name : EvaluvateTestcase
  *
  * Description  : This function evaluate the test case by sending the string 
  *                passed to it and wait for the result from AUT				   
  * 
  * Parameters   : message to AUT(test case in the preorganaized format from the csv file)
  * 
  * Return Value : result for the test case recieved from AUT
  * 
  * 
  */
  
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

 /** 
  * 
  *Function Name : readCSV
  *
  * Description  : read the csv file line by line and save it in a vector and 
  *        		   seperate the test cases and expected results 				   
  * 
  * Parameters   : name of the file to be read(testcase csv filename)
  * 
  * Return Value : None
  * 
  * 
  */
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


 /** 
  * 
  *Function Name : getFileContent
  *
  * Description  : read the csv file line by line and save it in a vector 				   
  * 
  * Parameters   : fileName name of the file to be read,
  *				   vecOfStrs variable to save data from csv line by line
  * 
  * Return Value : true on successful read & false on read failure.
  * 
  * 
  */
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

  /** 
  * 
  *Function Name : setStopMain
  *
  * Description  : This function sets boolean variable to stop sending test message 				   
  * 
  * Parameters   : stop boolean variable
  * 
  * Return Value : None
  * 
  * 
  */
  
void ServerUtility::setStopMain(bool s)
{
   m_stop_main = s;
}

  /** 
  * 
  *Function Name : getStopMain
  *
  * Description  : This function gets boolean variable to stop sending test message 				   
  * 
  * Parameters   : None
  * 
  * Return Value : stop boolean variable(m_stop_main)
  * 
  * 
  */
  
bool ServerUtility::getStopMain()
{
   return m_stop_main;
}
