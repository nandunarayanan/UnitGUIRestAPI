///////////////////////////////////////////////////////////////////////////////
// @File Name:     Logger.cpp                                                //
// @Author:           					                       //
// @Version:        		                                              //
// @L.M.D:         					                       //
// @Description:   For Logging into file                                     //
//                                                                           // 
// Detail Description:                                                       //
// Implemented complete logging mechanism, Supporting multiple logging type  //
// like as file based logging, console base logging etc. It also supported   //
// for different log type.                                                   //
//                                                                           //
// Thread Safe logging mechanism. Compatible with VC++ (Windows platform)    //
// as well as G++ (Linux platform)                                           //
//                                                                           //
// Supported Log Type: ERROR, ALARM, ALWAYS, INFO, BUFFER, TRACE, DEBUG      //
//                                                                           //
// No control for ERROR, ALRAM and ALWAYS messages. These type of messages   //
// should be always captured.                                                //
//                                                                           //
// BUFFER log type should be use while logging raw warn or raw messages      //
//                                                                           //
// Having direct interface as well as C++ Singleton inface. can use          //
// whatever interface want.                                                  //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// C++ Header File(s)
#include <iostream>
#include <cstdlib>
#include <ctime>

// Code Specific Header Files(s)
#include "Logger.h"

using namespace std;
using namespace CPlusPlusLogging;

Logger* Logger::m_Instance = 0;

// Log file name. File name should be change from here only
const string logFileName = "MyLogFile.log";
    
/*!
 * @brief Default Constructor
 */
Logger::Logger()
{
   m_File.open(logFileName.c_str(), ios::out|ios::app);
   m_LogLevel	= LOG_LEVEL_DEBUG;
   m_LogType	= FILE_LOG;

   // Initialize mutex
#ifdef WIN32
   InitializeCriticalSection(&m_Mutex);
#else
   int ret=0;
   ret = pthread_mutexattr_settype(&m_Attr, PTHREAD_MUTEX_ERRORCHECK_NP);
   if(ret != 0)
   {   
      printf("Logger::Logger() -- Mutex attribute not initialize!!\n");
      exit(0);
   }   
   ret = pthread_mutex_init(&m_Mutex,&m_Attr);
   if(ret != 0)
   {   
      printf("Logger::Logger() -- Mutex not initialize!!\n");
      exit(0);
   }   
#endif
}

/*!
 * @brief Default Desctructor
 */
Logger::~Logger()
{
   m_File.close();
#ifdef WIN32
   DeleteCriticalSection(&m_Mutex);
#else
   pthread_mutexattr_destroy(&m_Attr);
   pthread_mutex_destroy(&m_Mutex);
#endif
}
   
/*!
 * @brief This function returns a reference Logger instance
 * @return Reference to Logger object
 */
Logger* Logger::getInstance() throw ()
{
   if (m_Instance == 0) 
   {
      m_Instance = new Logger();
   }
   return m_Instance;
}

/*!
 * @brief Wrapper function for lock
 */
void Logger::lock()
{
#ifdef WIN32
   EnterCriticalSection(&m_Mutex);
#else
   pthread_mutex_lock(&m_Mutex);
#endif
}

/*!
 * @brief Wrapper function for unlock
 */
void Logger::unlock()
{
#ifdef WIN32
   LeaveCriticalSection(&m_Mutex);
#else
   pthread_mutex_unlock(&m_Mutex);
#endif
}

/*!
 * @brief This function is the Interface to log into File
 */
void Logger::logIntoFile(std::string& data)
{
   lock();
   m_File << getCurrentTime() << "  " << data << endl;
   unlock();
}

/*!
 * @brief This function is the Interface to log into Console
 */
void Logger::logOnConsole(std::string& data)
{
   std::cout << getCurrentTime() << "  " << data << std::endl;
}

/*!
 * @brief function to get the current time
 */
string Logger::getCurrentTime()
{
   string currTime;
   //Current date/time based on current time
   time_t now = time(0); 
   // Convert current time to string
   currTime.assign(ctime(&now));

   // Last charactor of currentTime is "\n", so remove it
   string currentTime = currTime.substr(0, currTime.size()-1);
   return currentTime;
}

/*!
 * @brief This function is the Interface for Error Log 
 * @param text to be printed as error
 */ 
void Logger::error(const char* text) throw()
{
   string data;
   data.append("[ERROR]: ");
   data.append(text);

   // ERROR must be captured always
   if(m_LogType == FILE_LOG)
   {
      logIntoFile(data);
   }
   else if(m_LogType == CONSOLE)
   {
      logOnConsole(data);
   }
}

/*!
 * @brief This function is the Interface for Error Log 
 * @param text to be printed as error
 */ 
void Logger::error(const std::string& text) throw()
{
   error(text.data());
}

/*!
 * @brief This function is the Interface for Error Log 
 * @param text to be printed as error
 */ 
void Logger::error(std::ostringstream& stream) throw()
{
   string text = stream.str();
   error(text.data());
}

/*!
 * @brief This function is the Interface for Warning Log 
 * @param text to be printed as Warning
 */ 
void Logger::warn(const char* text) throw()
{
   // Buffer is the special case. So don't add log level
   // and timestamp in the warn message. Just log the raw bytes.
   if((m_LogType == FILE_LOG) && (m_LogLevel >= LOG_LEVEL_WARN))
   {
      lock();
      m_File << text << endl;
      unlock();
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel >= LOG_LEVEL_WARN))
   {
      cout << text << endl;
   }
}

/*!
 * @brief This function is the Interface for Warning Log 
 * @param text to be printed as Warning
 */ 
void Logger::warn(const std::string& text) throw()
{
   warn(text.data());
}

/*!
 * @brief This function is the Interface for Warning Log 
 * @param text to be printed as Warning
 */ 
void Logger::warn(std::ostringstream& stream) throw()
{
   string text = stream.str();
   warn(text.data());
}

/*!
 * @brief This function is the Interface for Info Log 
 * @param text to be printed as Info
 */ 
void Logger::info(const char* text) throw()
{
   string data;
   data.append("[INFO]: ");
   data.append(text);

   if((m_LogType == FILE_LOG) && (m_LogLevel >= LOG_LEVEL_INFO))
   {
      logIntoFile(data);
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel >= LOG_LEVEL_INFO))
   {
      logOnConsole(data);
   }
}

/*!
 * @brief This function is the Interface for Info Log 
 * @param text to be printed as Info
 */
void Logger::info(const std::string& text) throw()
{
   info(text.data());
}

/*!
 * @brief This function is the Interface for Info Log 
 * @param text to be printed as Info
 */
void Logger::info(std::ostringstream& stream) throw()
{
   string text = stream.str();
   info(text.data());
}

/*!
 * @brief This function is the Interface for Debug Log 
 * @param text to be printed as Debug
 */
void Logger::debug(const char* text) throw()
{
   string data;
   data.append("[DEBUG]: ");
   data.append(text);

   if((m_LogType == FILE_LOG) && (m_LogLevel >= LOG_LEVEL_DEBUG))
   {
      logIntoFile(data);
   }
   else if((m_LogType == CONSOLE) && (m_LogLevel >= LOG_LEVEL_DEBUG))
   {
      logOnConsole(data);
   }
}

/*!
 * @brief This function is the Interface for Debug Log 
 * @param text to be printed as Debug
 */
void Logger::debug(const std::string& text) throw()
{
   debug(text.data());
}

/*!
 * @brief This function is the Interface for Debug Log 
 * @param text to be printed as Debug
 */
void Logger::debug(std::ostringstream& stream) throw()
{
   string text = stream.str();
   debug(text.data());
}

/*!
 * @brief This function is the Interfaces to control log levels. All the levels above the parameter passed will be enabled
 * @param logLevel is considered as minimum level to be enabled
 */
void Logger::updateLogLevel(LogLevel logLevel)
{
   m_LogLevel = logLevel;
}

/*!
 * @brief This function is the Interfaces to Enable all log levels
 */
void Logger::enaleLog()
{
   m_LogLevel = ENABLE_LOG; 
}

/*!
 * @brief This function is the Interfaces to Disable all log levels, except error
 */
void Logger:: disableLog()
{
   m_LogLevel = DISABLE_LOG;
}

/*!
 * @brief This function is the Interface to enable Console or File Logging
 * @param logType parameter which need to be enabled as logtype
 */
void Logger::updateLogType(LogType logType)
{
   m_LogType = logType;
}
/*!
 * @brief This function is the Interface to enable Console Logging
 */
void Logger::enableConsoleLogging()
{
   m_LogType = CONSOLE; 
}

/*!
 * @brief This function is the Interface to enable File Logging
 */
void Logger::enableFileLogging()
{
   m_LogType = FILE_LOG ;
}
