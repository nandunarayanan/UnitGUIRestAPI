
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class ServerUtility
{
  string m_msgRecived;
  string m_msgPublish;
  bool m_stop_main;
  
  public:
     
    vector<string> words;
    vector<string> words1;
  
    string getMsg();    
    void setMsg(string msg);
    void setStopMain(bool s);
    bool getStopMain();
    string getMsgPublish();    
    void setMsgPublish(string msg);
    string EvaluvateTestcase(string msg);
    void readCSV();
    static bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs);

    ServerUtility (): m_msgRecived("")
	     , m_msgPublish("")
	     , m_stop_main(false)
   {
	
   }
};

void SubscriberMain(ServerUtility* s);
void PublisherMain(ServerUtility* s);
