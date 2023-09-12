#include "phonebook.h"
#include <iostream>
#include <iomanip>

int main()
{
	PhoneBook	pb;
	std::string	input;

	while (1)
	{
		std::cout << "Menu" << std::endl << "Commande : ADD / SEARCH / EXIT" << std::endl;
		std::cout << "Enter : ";
		std::cin >> input;
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
		{
			std::cout << " Exiting program " << std::endl;
			break ;
		}
		else
			std::cout << "Wrong input" << std::endl;
	}
	return (0);
}