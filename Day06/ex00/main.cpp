#include <iostream>
#include <iomanip>

void convertToChar(std::string str) {
  char out;

  try {
    std::cout << "char: ";
    out = static_cast<char>(std::stoi(str));
    if (out > 32 && out < 127)
      std::cout << "'"<< out << "'"<< std::endl;
    else
      std::cout << "Non displayable" << std::endl;
  }
  catch (std::exception &e) {
    std::cout << "impossible" << std::endl;
  }
}

void convertToInt(std::string str) {
  try {
    std::cout << "int: ";
    std::cout << std::stoi(str) << std::endl;
  }
  catch (std::exception &e){
    std::cout << "impossible" << std::endl;
  }
}

void convertToFloat(std::string str) {
  try {
    std::cout << "float: ";
    std::cout << static_cast<float>(std::stof(str)) << "f" << std::endl;
  }
  catch (std::exception &e){
    std::cout << "impossible" << std::endl;
  }
}

void convertToDouble(std::string str) {
  try {
    std::cout << "double: ";
    std::cout << static_cast<float>(std::stof(str)) << std::endl;
  }
  catch (std::exception &e){
    std::cout << "impossible" << std::endl;
  }
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./convert [value]" << std::endl;
    return 0;
  }
  std::string str;
  str = std::string(argv[1]);
  std::cout << std::fixed << std::setprecision(1);
  convertToChar(str);
  convertToInt(str);
  convertToFloat(str);
  convertToDouble(str);
}
