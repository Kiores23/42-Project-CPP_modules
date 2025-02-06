#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	iron("Iron", 150);
	Bureaucrat	bronze("Bronze", 125);
	Bureaucrat	gold("Gold", 100);
	Bureaucrat	platinum("Platinum", 75);
	Bureaucrat	diamond("Diamond", 50);
	Bureaucrat	master("Master", 25);
	Bureaucrat	grand_master("Grand Master", 10);
	Bureaucrat	challenger("Challenger", 1);

	std::cout << "Shrubbery test" << std::endl;
	ShrubberyCreationForm	Shrubbery("House");

	iron.signForm(Shrubbery);
	bronze.signForm(Shrubbery);
	iron.executeForm(Shrubbery);
	bronze.executeForm(Shrubbery);

	std::cout << std::endl << "Robotomy test" << std::endl;
	RobotomyRequestForm	Robotomy("Harry");

	gold.signForm(Robotomy);
	platinum.signForm(Robotomy);
	diamond.signForm(Robotomy);
	diamond.executeForm(Robotomy);
	master.executeForm(Robotomy);

	std::cout << std::endl << "Presidential test" << std::endl;
	PresidentialPardonForm	Presidential("Damien");

	master.signForm(Presidential);
	grand_master.executeForm(Presidential);
	challenger.executeForm(Presidential);
}