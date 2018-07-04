
//#include "Form.hpp"
// #include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
int main() {

  Bureaucrat b1("John", 1);
  ShrubberyCreationForm         f1("SCF1");
  RobotomyRequestForm         f2("RMF1");
  PresidentialPardonForm  f3("PPF1");
  b1.signForm(f1);
  b1.signForm(f2);
  b1.signForm(f3);
  b1.executeForm(f1);
  b1.executeForm(f2);
  b1.executeForm(f3);

  Bureaucrat b2("Max", 20);
  b2.signForm(f1);
  b2.signForm(f2);
  b2.signForm(f3);
  b2.executeForm(f1);
  b2.executeForm(f2);
  b2.executeForm(f3);

  Bureaucrat b3("Dan", 150);
  b3.signForm(f1);
  b3.signForm(f2);
  b3.signForm(f3);
  b3.executeForm(f1);
  b3.executeForm(f2);
  b3.executeForm(f3);

  return 0;
}
