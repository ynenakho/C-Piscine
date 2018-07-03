
#include "Form.hpp"
 #include "Bureaucrat.hpp"

int main() {
  Form form1("New form", 60, 120);
  Bureaucrat b1("John", 100);
  Bureaucrat b2("Vasya", 30);
  b1.signForm(form1);
  b2.signForm(form1);
  return 0;
}
