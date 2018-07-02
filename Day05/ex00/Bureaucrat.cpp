#include "Bureaucrat.hpp"

std::ostream &operator<< (std::ostream &res, const Bureaucrat &obj) {
  res << "<" << obj.getName() << ">, bureaucrat grade <" << obj.getGrade() << ">.";
  return res;
}

Bureaucrat &Bureaucrat::operator= (const Bureaucrat &obj){
  this->grade = obj.getGrade();
  return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) {
  try {
    if (grade < 1) {
      this->grade = 1;
      throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150) {
      this->grade = 150;
      throw Bureaucrat::GradeTooLowException();
    }
    else
      this->grade = grade;
  }
  catch (GradeTooHighException e) {
    std::cerr << e.what() << std::endl;

  }
  catch (GradeTooLowException e) {
    std::cerr << e.what() << std::endl;
  }
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::incrementGrade() {
  try {
    if (this->grade == 1) {
      throw Bureaucrat::GradeTooHighException();
    }
    else
      this->grade--;
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

void Bureaucrat::decrementGrade() {
  try {
    if (this->grade == 150) {
      throw Bureaucrat::GradeTooLowException();
    }
    else
      this->grade++;
  }
  catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}

int Bureaucrat::getGrade() const {
  return this->grade;
}

std::string Bureaucrat::getName() const{
  return this->name;
}
