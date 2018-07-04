#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "OfficeBlock.hpp"

int main()
{
Intern idiotOne;
Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
OfficeBlock ob;
ob.setIntern(idiotOne);
ob.setSigner(bob);
ob.setExecutor(hermes);
try
{
ob.doBureaucracy("mutant pig termination", "Pigley");
}
catch (std::exception & e)
{
std::cout << e.what() << std::endl;
}
}
