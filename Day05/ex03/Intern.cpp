#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern &Intern::operator= (const Intern &rhs) {
  static_cast <void> (rhs);
  return (*this);
}

Intern::Intern(const Intern &src) {
  *this = src;
  return ;
}

Intern::~Intern() {}

Intern::Intern() {
  funcs[0] = &Intern::newPresidentialPardonForm;
  funcs[1] = &Intern::newRobotomyRequestForm;
  funcs[2] = &Intern::newShrubberyCreationForm;
}

std::string Intern::names[3] = {
  "presidential pardon",
  "robotomy request",
  "shrubbery creation"
};

Form *Intern::makeForm(std::string name, std::string target) {
    try {
        for (int i = 0; i < 3; i++) {
          if (name == Intern::names[i])
            return (this->*funcs[i])(target);
        }
        throw Intern::InternException();
    }
    catch (std::exception &e) {
        std::cout << name << " "<< e.what() << std::endl;
        return NULL;
    }
}

Form* Intern::newPresidentialPardonForm(std::string target) {
  std::cout << "Intern creates Presidential Pardon form" << std::endl;
  return (new PresidentialPardonForm(target));
}
Form* Intern::newRobotomyRequestForm(std::string target){
  std::cout << "Intern creates Robotomy Request form" << std::endl;
  return (new RobotomyRequestForm(target));
}
Form* Intern::newShrubberyCreationForm(std::string target){
  std::cout << "Intern creates Shrubbery Creation form" << std::endl;
  return (new ShrubberyCreationForm(target));
}
