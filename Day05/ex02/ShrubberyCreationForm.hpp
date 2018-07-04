#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include <fstream>

class Form;
class Bureaucrat;

class ShrubberyCreationForm : public Form {
  private:
    static const int sign = 145;
    static const int exec = 137;

  public:
    ShrubberyCreationForm(std::string target = "Default target");
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator= (const ShrubberyCreationForm &obj);

    int getSignInGrade() const;
    int getExcecuteGrade() const;

    virtual void execute(Bureaucrat const & executor) const;
};

#endif
