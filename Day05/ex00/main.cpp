#include "Bureaucrat.hpp"

int main() {
  Bureaucrat b1("John", 160);
  Bureaucrat b2("Andy", -1);
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  b1.decrementGrade();
  b2.incrementGrade();
  b2.decrementGrade();
  b1.incrementGrade();
  b2.decrementGrade();
  b1.incrementGrade();
  std::cout << b1 << std::endl;
  std::cout << b2 << std::endl;
  Bureaucrat b3("Vasya", 100);
  std::cout << b3 << std::endl;
  return 0;

}
