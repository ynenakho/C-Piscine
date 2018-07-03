#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
  private:
    std::string const name;
    const int signInGrade;
    const int excecuteGrade;
    bool signedIn;

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
    
    Form &operator= (const Form &obj);
    Form(std::string name, const int signInGrade, const int excecuteGrade);
    ~Form();
    std::string getName() const;
    int getSignInGrade() const;
    int getExcecuteGrade() const;
    bool getSignedIn() const;
    void beSigned(Bureaucrat &obj);
};

std::ostream &operator<< (std::ostream &res, const Form &obj);

#endif
