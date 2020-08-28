#include <string>


class AUTUtility 
{
  std::string m_msg;
  std::string m_Resultmsg;
  int messageCounter;
  
  public:
    m_stop;
    std::string getMsg();    
    void setMsg(std::string msg);
    std::string getResultMsgPub();    
    void setResultMsgPub(std::string msg);
 
    AUTUtility();

};


void SubscriberMain(AUTUtility* c);
void PublisherMain(AUTUtility* c);
