#include "Phonebook.h"
#include <sstream>
#include <limits>

PhoneBook::PhoneBook(){
	n_contact = 0;
}

PhoneBook::~PhoneBook(){
}

int	PhoneBook::add(){
	int	r;
	
	std::cout << std::endl << "CONTACT CREATION" << std::endl;
	r = book[n_contact].edit_contact(n_contact);
	n_contact++;
	n_contact = n_contact % 8;
	return r;
}

int	PhoneBook::search(){
	if (book[0].get_index() == -1)
		std::cout << "No contact saved" << std::endl;
	else
	{
		char index;
		std::cout << std::endl << "CONTACT LIST" << std::endl;
		std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME" << std::endl;
		for (index = '0'; book[index - 48].get_index() == index - 48 ; index++)
			std::cout << book[index - 48].get_compressed_value() << std::endl;
		std::cout << "Which contact do you want ? " << std::endl << "Index : ";
		if (!(std::cin >> index)) {
			std::cout << "Search aborted" << std::endl;
			return 1;
        }
		while (std::cin.peek() != '\n' || index < '0' || index >= '8' 
			|| book[index - 48].get_index() == -1)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Index invalid" << std::endl << std::endl;
			std::cout << "Which contact do you want ? " << std::endl << "Index : ";
			if (!(std::cin >> index)) {
				std::cout << "Search aborted" << std::endl;
				return 1;
			}
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << book[index - 48].ToString();
	}
	return 0;
}
