#include "Phonebook.h"
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
	PhoneBook	pb;
	std::string	input;

	while (1)
	{
		std::cout << "MENU" << std::endl << "Orders : ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Enter : ";
		if (!(std::getline(std::cin, input)))
            break;
		else if (input == "ADD")
		{
			if (pb.add())
				break;
		}
		else if (input == "SEARCH")
		{
			if (pb.search())
				break;
		}
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Wrong input" << std::endl;
		std::cout << std::endl;
	}
	std::cout << " Exiting program " << std::endl;
	return (0);
}