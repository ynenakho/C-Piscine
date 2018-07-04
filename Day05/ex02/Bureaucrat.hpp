#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat {
  private:
    std::string const name;
    int grade;

  public:
    class GradeTooHighException : public std::exception {
     public:
       virtual const char* what() const throw() {
         return ("Grade is too high.");
       }
    };

    class GradeTooLowException : public std::exception {
     public:
       virtual const char* what() const throw() {
         return ("Grade is too low.");
       }
    };

    Bureaucrat(std::string name = "Default", int grade = 150);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();

    Bureaucrat &operator= (const Bureaucrat &obj);

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form & obj);
    void executeForm(Form const & form);
};

std::ostream &operator<< (std::ostream &res, const Bureaucrat &obj);

#endif
