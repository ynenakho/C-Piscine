#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
	Form("Default target", "Shrubbery Creation", this->getSignInGrade(), this->getExcecuteGrade()) {
    *this = src;
    return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &rhs) {
    static_cast <void> (rhs);
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) :
  Form(target, "Shrubbery Creation", this->getSignInGrade(), this->getExcecuteGrade())
{}

int ShrubberyCreationForm::getSignInGrade() const {
  return this->sign;
}

int ShrubberyCreationForm::getExcecuteGrade() const {
  return this->exec;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
  std::ofstream outputFile;
  Form::execute(executor);
  outputFile.open(this->getTarget() + "_shrubbery");
  if (outputFile.fail())
    std::cerr << "Error openning the outfile" << std::endl;
  outputFile << "    \\/ |    |/ "  << std::endl;
  outputFile << "      \\/ / \\||/  /_/___/_"  << std::endl;
  outputFile << "       \\/   |/ \\/"  << std::endl;
  outputFile << "  _\\__\\_\\   |  /_____/_"  << std::endl;
  outputFile << "         \\  | /          /" << std::endl;
  outputFile << "__ _-----`  |{,-----------~"  << std::endl;
  outputFile << "          \\ }{"  << std::endl;
  outputFile << "           }{{"  << std::endl;
  outputFile << "           }}{"  << std::endl;
  outputFile << "           {{}"  << std::endl;
  outputFile << "  , -=-~{ .-^- _"  << std::endl;
  outputFile << "            }"  << std::endl;
  outputFile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
