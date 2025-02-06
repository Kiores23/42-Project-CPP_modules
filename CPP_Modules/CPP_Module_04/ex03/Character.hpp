#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "ICharacter.hpp"
# include "Inventory.hpp"

class Character : public ICharacter
{
	private:
		std::string	_Name;
		Inventory	_Inventory;

	public:
		Character();
		Character(std::string name);
		Character(Character const &other);
		Character& operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif