#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
	Form("Default target", "Robotomy RequestForm", this->getSignInGrade(), this->getExcecuteGrade()) {
    *this = src;
    return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator= (const RobotomyRequestForm &rhs) {
    static_cast <void> (rhs);
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
  Form(target, "Robotomy Request", this->getSignInGrade(), this->getExcecuteGrade())
{}

int RobotomyRequestForm::getSignInGrade() const {
  return this->sign;
}

int RobotomyRequestForm::getExcecuteGrade() const {
  return this->exec;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  std::srand(std::time(0));
  Form::execute(executor);
  if (std::rand() % 2)
    std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
  else
    std::cout << this->getTarget() << " failed to robotomize." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
