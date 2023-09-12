#ifndef CONTACT_H
#define CONTACT_H

# include <iostream>

class	Contact {
	private :
		int			index;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;
	public :
		Contact();
		std::string ToString();
		void		edit_contact(int i);
		int			get_index();
		std::string	get_compressed_value();
};

#endif