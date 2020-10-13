/*!
 * @file ServerUtility.h
 * This header file contains the declaration of Utility functions required for server.
 *
 */

#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

/*!
 * @brief This class represents the Server Utility variables and functions
 */
class ServerUtility
{
    /*!
     * @brief Private member variables.
     */
    string m_msgRecived;
    string m_msgPublish;
    bool m_stop_main;
  
  public:
     
    /*!
     * @brief Public member variables.
     */
    vector<string> words;
    vector<string> words1;
  
    /*!
     * @brief This function returns a message recieved from AUT
     * @return recieved message(m_msgRecived)
     */
    string getMsg();
	
    /*!
     * @brief This function sets message recieved from AUT
     * @param recieved message
     */
    void setMsg(string msg);
	
    /*!
     * @brief This function sets boolean variable to stop sending test message
     * @param stop boolean variable
     */
    void setStopMain(bool s);
	
    /*!
     * @brief This function gets boolean variable to stop sending test message
     * @return stop boolean variable(m_stop_main)
     */
    bool getStopMain();
	
    /*!
     * @brief This function gets the message to be published to AUT
     * @return message to be published(m_msgPublish)
     */
    string getMsgPublish();    
	
    /*!
     * @brief This function sets the message to be published to AUT(m_msgPublish)
     * @param message to be published
     */
    void setMsgPublish(string msg);
	
    /*!
     * @brief This function evaluate the test case by sending the string 
	 *        passed to it and wait for the result from AUT
     * @param test case
     * @return result for the test case recieved from AUT
     */
    string EvaluvateTestcase(string msg);
	
    /*!
     * @brief read the csv file line by line and save it in a vector and seperate the test cases and expected results
     * @param name of the file to be read
     */
    void readCSV(std::string filename);
	
    /*!
     * @brief read the csv file line by line and save it in a vector
     * @param fileName name of the file to be read
     * @param vecOfStrs variable to save data from csv line by line
     */
    static bool getFileContent(std::string fileName, std::vector<std::string> & vecOfStrs);

    /*!
     * @brief Default constructor.
     */
    ServerUtility (): m_msgRecived("")
	     , m_msgPublish("")
	     , m_stop_main(false)
   {
	
   }
};

/*!
 * @brief Subscriber Main thread function to send the messages from Test runner to test environment
 * @param s ServerUtility class pointer
 */
void SubscriberMain(ServerUtility* s);

/*!
 * @brief Publisher Main thread function to recieve the messages from Test environment to test runner
 * @param s ServerUtility class pointer
 */
void PublisherMain(ServerUtility* s);
