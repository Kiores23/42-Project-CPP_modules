
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class	PhoneBook {
	private:
	int		n_contact;
	Contact book[8];
	public:
	PhoneBook();
	~PhoneBook();
	int	add();
	int	search();
};

#endif