#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << std::endl << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."
	<< std::endl << "I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << std::endl << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl 
	<< "You didn’t put enough bacon in my burger!" << std::endl << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << std::endl << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl 
	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << std::endl << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!" << std::endl << "I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	tab_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			n_level;

	for (n_level = 0; n_level < 4; n_level++)
	{
		if (level == tab_level[n_level])
			break;
	}
	switch (n_level)
    {
		case 0:
			this->debug();
			//	Intentional fall-through
		case 1:
			this->info();
			//	Intentional fall-through
		case 2:
			this->warning();
			//	Intentional fall-through
		case 3:
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

