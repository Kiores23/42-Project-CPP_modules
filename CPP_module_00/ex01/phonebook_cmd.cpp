#include "phonebook.h"
#include <sstream>

PhoneBook::PhoneBook(){
	n_contact = 0;
}

void	PhoneBook::add(){
	book[n_contact].edit_contact(n_contact);
	n_contact++;
	n_contact = n_contact % 8;
}

void	PhoneBook::search(){
	if (book[0].get_index() == -1)
		std::cout << "No contact saved" << std::endl;
	else
	{
		int index;
		std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME" << std::endl;
		for (index = 0; book[index].get_index() == index ; index++)
			std::cout << book[index].get_compressed_value() << std::endl;
		std::cout << "Which contact do you want ? " << std::endl;
		std::cin >> index;
		if(index < 0 || index >= 8 ){
			std::cout << "Index invalid" << std::endl;
		} else if(book[index].get_index() == -1){
			std::cout << "Index invalid" << std::endl;
		}else{
			std::cout << book[index].ToString() << std::endl;
		}
	}
}
