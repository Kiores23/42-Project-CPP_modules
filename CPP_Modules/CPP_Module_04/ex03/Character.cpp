#include "Character.hpp"

Character::Character() : _Name("No name") {}

Character::Character(std::string name) : _Name(name) {}

Character::Character(Character const &other) {
	*this = other;
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_Name = other._Name;
		_Inventory = other._Inventory;
	}
	return *this;
}

Character::~Character() {}

std::string const & Character::getName() const {
	return _Name;
}

void	Character::equip(AMateria* m) {
	_Inventory.setItem(m);
}

void	Character::unequip(int idx) {
	_Inventory.unsetItem(idx);
}

void	Character::use(int idx, ICharacter& target) {
	if (_Inventory.getItem(idx))
		_Inventory.getItem(idx)->use(target);
	else
		std::cout << "Item not found" << std::endl;
}
