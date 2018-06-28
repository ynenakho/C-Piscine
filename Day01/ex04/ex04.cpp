#include <iostream>

int main()
{
  std::string str = "HI THIS IS BRAIN";
  std::string *strPtr = &str;
  std::string &strRef = str;

  std::cout << "Pointer  : " << *strPtr << std::endl;
  std::cout << "Reference: " << strRef << std::endl;
  return 0;
}
