#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <stdexcept>



class Bureaucrat {
  private:
    std::string const name;
    int grade;

  public:
    class GradeTooHighException : public std::exception {
     public:
       virtual const char* what() const throw() {
         return ("Grade is too high. Grade set to 1");
       }
    };

    class GradeTooLowException : public std::exception {
     public:
       virtual const char* what() const throw() {
         return ("Grade is too low. Grade set to 150");
       }
    };
    Bureaucrat &operator= (const Bureaucrat &obj);
    Bureaucrat(std::string name = "Default", int grade = 150);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
};

std::ostream &operator<< (std::ostream &res, const Bureaucrat &obj);

#endif
