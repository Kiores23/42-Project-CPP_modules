#include "Contact.h"
#include <limits>
#include <sstream>
#include <iostream>

Contact::Contact() {
	index = -1;
}

Contact::~Contact() {
}

int	Contact::edit_contact(int i) {
	index = i;
	std::cout << "Index : " << index << std::endl;
	first_name = "";
	while (first_name.empty()){
		std::cout << "First name : ";
		if (!(std::getline(std::cin, first_name))) {
			std::cout << "Add aborted" << std::endl;
            return 1;
        }
	}
	last_name = "";
	while (last_name.empty()){
		std::cout << "Last name : ";
		if (!(std::getline(std::cin, last_name))) {
			std::cout << "Add aborted" << std::endl;
            return 1;
        }
	}
	nickname = "";
	while (nickname.empty()){
		std::cout << "Nickname : ";
		if (!(std::getline(std::cin, nickname))) {
			std::cout << "Add aborted" << std::endl;
            return 1;
        }
	}
	phone_number = "";
	while (phone_number.empty()){
		std::cout << "Phone number : ";
		if (!(std::getline(std::cin, phone_number))) {
			std::cout << "Add aborted" << std::endl;
            return 1;
        }
	}
	darkest_secret = "";
	while (darkest_secret.empty()){
		std::cout << "Darkest secret : ";
		if (!(std::getline(std::cin, darkest_secret))) {
			std::cout << "Add aborted" << std::endl;
            return 1;
        }
	}
	std::cout << "Contact successful created ! " << std::endl;
	return 0;
}

int	Contact::get_index(){
	return (index);
}

std::string TableFormat(std::string content) {
	if (content.length() <= 9) {
		std::string res = content;
		while(res.length() < 10){
			res += ' ';
		}
		return res;
	} else if (content.length() == 10) {
		return content;
	} else {
		return content.substr(0, 9) + ".";
	}
}

std::string	Contact::get_compressed_value(){
	std::stringstream	str;
	
	
	str << (int)index << "         ";	
	str << "|" << TableFormat(first_name);
	str << "|" << TableFormat(last_name);
	str << "|" << TableFormat(nickname);
	return (str.str());
}

std::string Contact::ToString(){
	std::stringstream ss;
	ss << "First Name : " << first_name << std::endl;
	ss << "Last Name : " << last_name << std::endl;
	ss << "Nickname : " << nickname << std::endl;
	ss << "Phonenumber : " << phone_number << std::endl;
	ss << "Darkest secret : " << darkest_secret << std::endl;
	return ss.str();
}
