#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include <fstream>

class Form;
class Bureaucrat;

class RobotomyRequestForm : public Form {
  private:
    static const int sign = 72;
    static const int exec = 45;

  public:
    RobotomyRequestForm(std::string target = "Default target");
    RobotomyRequestForm(const RobotomyRequestForm &src);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator= (const RobotomyRequestForm &obj);

    int getSignInGrade() const;
    int getExcecuteGrade() const;

    virtual void execute(Bureaucrat const & executor) const;
};

#endif
