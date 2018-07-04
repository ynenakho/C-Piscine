#ifndef OFFICEBLOCK_H
# define OFFICEBLOCK_H
# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "Intern.hpp"

class	OfficeBlock {
	public:
    class NoInternException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
          return ("No Intern present.");
        }
		};

		class NoSignerException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
          return ("No Signer present.");
        }
		};

		class NoExecuterException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
          return ("No Executer present.");
        }
		};

		OfficeBlock();
		OfficeBlock(Intern &intern, Bureaucrat &signer, Bureaucrat &executer);
		virtual ~OfficeBlock();

		void	setIntern(Intern &obj);
		void	setSigner(Bureaucrat &obj);
		void	setExecutor(Bureaucrat &obj);

		void	doBureaucracy(std::string form, std::string target);

	private:
		Intern		*intern;
		Bureaucrat	*signer;
		Bureaucrat	*executer;
};

#endif
