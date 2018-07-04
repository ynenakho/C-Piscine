#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private:
    std::string const target;
    std::string const name;
    const int signInGrade;
    const int excecuteGrade;
    bool signedIn;

  public:
    class FormIsNotSigned : public std::exception {
     public:
       virtual const char* what() const throw() {
         return ("Form is not signed.");
       }
    };

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

    Form(const Form &src);
    Form(std::string const target = "Default target", std::string const name = "Default name", const int signInGrade = 50, const int excecuteGrade = 100);
    virtual ~Form() = 0;

    Form &operator= (const Form &obj);

    std::string getName() const;
    int getSignInGrade() const;
    int getExcecuteGrade() const;
    bool getSignedIn() const;
    void beSigned(Bureaucrat &obj);
    std::string getTarget() const;
    virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<< (std::ostream &res, const Form &obj);

#endif
