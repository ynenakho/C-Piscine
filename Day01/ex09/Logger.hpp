#ifndef LOGGER_HPP
# define LOGGER_HPP
# include <iostream>
# include <fstream>
# include <string>

class Logger {
private:
  std::string filename;
  void logToConsole(std::string str);
  void logToFile(std::string str);
  std::string makeLogEntry(const std::string msg);
public:
  Logger(std::string filename);
  void  log(std::string const & dest, std::string const & message);
};

#endif
