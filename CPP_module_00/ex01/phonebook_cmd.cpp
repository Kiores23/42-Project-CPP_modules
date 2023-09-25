#include "phonebook.h"
#include <sstream>
#include <limits>

PhoneBook::PhoneBook(){
	n_contact = 0;
}

void	PhoneBook::add(){
	std::cout << std::endl << "CONTACT CREATION" << std::endl;
	book[n_contact].edit_contact(n_contact);
	std::cout << "Contact successful created ! " << std::endl;
	n_contact++;
	n_contact = n_contact % 8;
}

void	PhoneBook::search(){
	if (book[0].get_index() == -1)
		std::cout << "No contact saved" << std::endl;
	else
	{
		char index;
		std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME" << std::endl;
		for (index = '0'; book[index - 48].get_index() == index - 48 ; index++)
			std::cout << book[index - 48].get_compressed_value() << std::endl;
		std::cout << "Which contact do you want ? " << std::endl << "Index : ";
		std::cin >> index;
		while (std::cin.peek() != '\n' || index < '0' || index >= '8' 
			|| book[index - 48].get_index() == -1)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Index invalid" << std::endl << std::endl;
			std::cout << "Which contact do you want ? " << std::endl << "Index : ";
			std::cin >> index;
		}
		std::cout << book[index - 48].ToString();
	}
}
