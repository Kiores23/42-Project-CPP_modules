#include "contact.h"
#include <sstream>

Contact::Contact() {
	index = -1;
}

void	Contact::edit_contact(int i) {
	index = i;
	std::cout << "Index : " << index << std::endl;
	std::getline(std::cin, first_name);

	first_name = "";
	while ( first_name.empty()){
		std::cout << "First name : ";
		std::getline(std::cin, first_name);
	}
	last_name = "";
	while ( last_name.empty()){
		std::cout << "Last name : ";
		std::getline(std::cin, last_name);
	}
	nickname = "";
	while ( nickname.empty()){
		std::cout << "Nickname : ";
		std::getline(std::cin, nickname);
	}
	phone_number = "";
	while ( phone_number.empty()){
		std::cout << "Phone number : ";
		std::getline(std::cin, phone_number);
	}
	darkest_secret = "";
	while ( darkest_secret.empty()){
		std::cout << "Darkest secret : ";
		std::getline(std::cin, darkest_secret);
	}
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
