#include "Logger.hpp"

Logger::Logger(std::string filename) {
  this->filename = filename;
  return;
}

void Logger::logToConsole(std::string str) {
  std::cout << str << std::endl;
  return;
}

  void Logger::logToFile(std::string str) {
    std::ofstream fileToWright(this->filename, std::ios::app);
    fileToWright << str << std::endl;
    return;
  }

std::string Logger::makeLogEntry(std::string msg) {
  time_t now = time(0);
  tm* localtm = localtime(&now);
  std::string tmp = asctime(localtm);
  tmp.erase(tmp.end() - 1);
  std::string output = "[" + tmp + "]" + msg;
  return output;
}

void  Logger::log(std::string const & dest, std::string const & message) {
  std::string actionsArray[2] = { "logToConsole" ,"logToFile"};
  typedef void (Logger::*Actions)(std::string str);
  Actions actions[2] = {&Logger::logToConsole, &Logger::logToFile};
  std::string newStr = message;
  for (int i = 0; i < 2; i++)
    if (actionsArray[i] == dest)
      (this->*actions[i])(this->makeLogEntry(newStr));
}
