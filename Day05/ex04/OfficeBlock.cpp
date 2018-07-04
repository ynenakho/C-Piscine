#include "OfficeBlock.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

OfficeBlock::OfficeBlock() :
	intern(NULL),
	signer(NULL),
	executer(NULL) {}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer) :
	intern(&intern),
	signer(&signer),
	executer(&executer) {}

OfficeBlock::~OfficeBlock() {}

void OfficeBlock::doBureaucracy(std::string form_name, std::string target) {
	Form		*form = NULL;

	if (!this->intern)
		throw OfficeBlock::NoInternException();
	form = this->intern->makeForm(form_name, target);
	if (!form)
		return ;
	if (!this->signer)
		throw OfficeBlock::NoSignerException();
	this->signer->signForm(*form);
	if (!this->executer)
		throw OfficeBlock::NoExecuterException();
	this->executer->executeForm(*form);
}

void OfficeBlock::setIntern(Intern &obj) {
	std::cout << "Set intern to an office block" << std::endl;
	this->intern = &obj;
}

void OfficeBlock::setSigner(Bureaucrat &obj) {
	std::cout << "Set signer " << obj << " to an office block" << std::endl;
	this->signer = &obj;
}

void OfficeBlock::setExecutor(Bureaucrat &obj) {
	std::cout << "Set executor " << obj << " to an office block" << std::endl;
	this->executer = &obj;
}
