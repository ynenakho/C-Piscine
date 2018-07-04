#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	Form("Default target", "Presidential Pardon", this->getSignInGrade(), this->getExcecuteGrade()) {
    *this = src;
    return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator= (const PresidentialPardonForm &rhs) {
    static_cast <void> (rhs);
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
  Form(target, "Presidential Pardon", this->getSignInGrade(), this->getExcecuteGrade())
{}

int PresidentialPardonForm::getSignInGrade() const {
  return this->sign;
}

int PresidentialPardonForm::getExcecuteGrade() const {
  return this->exec;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  Form::execute(executor);
  std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}
