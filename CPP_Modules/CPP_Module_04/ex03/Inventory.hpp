#ifndef INVENTORY_HPP
# define INVENTORY_HPP
# include "AMateria.hpp"
# include <iostream>

class	Inventory
{
	private:
		AMateria*	_Inventory[4];
		AMateria*	_Unequipped[8];

	public:
		Inventory();
		Inventory(const Inventory& other);
		Inventory& operator=(const Inventory& other);
		~Inventory();

		void		setItem(AMateria *item);
		void		unsetItem(int id);
		AMateria*	getItem(int id);
};

#endif