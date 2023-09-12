
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "contact.h"

class	PhoneBook {
	private:
	int		n_contact;
	Contact book[8];
	public:
	PhoneBook();
	void	add();
	void	search();
};

#endif