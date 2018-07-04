#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    *this = src;
    return ;
}

std::ostream &operator<< (std::ostream &res, const Bureaucrat &obj) {
  res << "<" << obj.getName() << ">, bureaucrat grade <" << obj.getGrade() << ">.";
  return res;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &obj){
  this->grade = obj.getGrade();
  return (*this);
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  }
  else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  else {
    this->grade = grade;
  }

}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
    if (this->grade == 1) {
      throw Bureaucrat::GradeTooHighException();
    }
    else
      this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade == 150) {
      throw Bureaucrat::GradeTooLowException();
    }
    else
      this->grade++;
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

std::string Bureaucrat::getName() const{
  return this->name;
}
