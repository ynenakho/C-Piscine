#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Intern {
  public:
    class InternException : public std::exception {
     public:
       virtual const char* what() const throw() {
         return ("form not found.");
       }
    };

    Intern(const Intern &src);
    Intern();
    ~Intern();

    Intern &operator= (const Intern &obj);
    Form *makeForm(std::string name, std::string target);

    typedef Form* (Intern::*InternFuncPointer)(std::string);
    
  private:
    InternFuncPointer funcs[3];
    static std::string names[3];
    Form* newPresidentialPardonForm(std::string target);
    Form* newRobotomyRequestForm(std::string target);
    Form* newShrubberyCreationForm(std::string target);
};

#endif
