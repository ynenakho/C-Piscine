 #include "Logger.hpp"

 int main()
 {
   Logger myLog("newlog.txt");
   myLog.log("logToConsole", "My 1 log");
   myLog.log("logToConsole", "My 2 log");
   myLog.log("logToFile", "My 3 log");
   myLog.log("logToFile", "My 4 log");
   return 0;
 }
