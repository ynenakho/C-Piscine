
#include "Intern.hpp"
// #include "Bureaucrat.hpp"

int main() {

  Intern someRandomIntern;
  Form* rrf;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
  rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
  rrf = someRandomIntern.makeForm("undefined", "Bender");
  return 0;
}
