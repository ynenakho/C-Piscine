#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include <fstream>

class Form;
class Bureaucrat;

class PresidentialPardonForm : public Form {
  private:
    static const int sign = 25;
    static const int exec = 5;

  public:
    PresidentialPardonForm(std::string target = "Default target");
    PresidentialPardonForm(const PresidentialPardonForm &src);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator= (const PresidentialPardonForm &obj);

    int getSignInGrade() const;
    int getExcecuteGrade() const;

    virtual void execute(Bureaucrat const & executor) const;
};

#endif
