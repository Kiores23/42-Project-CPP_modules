#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	pro("Bureaucrat master", 1);
	Intern		intern;
	AForm*		form;

	form = intern.makeForm("wrong", "Potatoes");
	form = intern.makeForm("ShrubberyCreationForm", "Potatoes");
	pro.signForm(*form);
	pro.executeForm(*form);
	delete form;
	form = intern.makeForm("RobotomyRequestForm", "Bill Gates");
	pro.signForm(*form);
	pro.executeForm(*form);
	delete form;
	form = intern.makeForm("PresidentialPardonForm", "6ix9ine");
	pro.signForm(*form);
	pro.executeForm(*form);
	AForm*		formCpy = new PresidentialPardonForm("Random");
	*formCpy = *form;
	pro.signForm(*formCpy);
	pro.executeForm(*formCpy);
	delete form;
	delete formCpy;
}