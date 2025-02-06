#include "Inventory.hpp"

Inventory::Inventory() {
	for (int i = 0; i < 4; i++)
			_Inventory[i] = NULL;
	for (int i = 0; i < 8; i++)
			_Unequipped[i] = NULL;
}

Inventory::Inventory(const Inventory& other) {
	*this = other;
}

Inventory& Inventory::operator=(const Inventory& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_Inventory[i])
				delete _Inventory[i];
			_Inventory[i] = NULL;
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._Inventory[i])
				_Inventory[i] = other._Inventory[i]->clone();
		}
		for (int i = 0; i < 8 && _Unequipped[i]; i++) {
			if (_Unequipped[i])
				delete _Unequipped[i];
		}
		for (int i = 0; i < 8; i++)
		{
			if (other._Unequipped[i])
				_Unequipped[i] = other._Unequipped[i]->clone();
		}
	}
	return *this;
}

Inventory::~Inventory() {
	for (int i = 0; i < 4; i++) {
		if (_Inventory[i])
			delete _Inventory[i];
	}
	for (int i = 0; i < 8 && _Unequipped[i]; i++) {
			if (_Unequipped[i])
				delete _Unequipped[i];
	}
}

void	Inventory::setItem(AMateria *item) {
	int i;

	for (i = 0; i < 4 && _Inventory[i]; i++)
		;
	if (i < 4)
		_Inventory[i] = item;
}

void	Inventory::unsetItem(int id) {
	int	i;

	for (i = 0; i < 8 && _Unequipped[i]; i++)
		;
	if (i < 8 && 0 <= id && id < 4 && _Inventory[id]) {
		_Unequipped[i] = _Inventory[id];
		_Inventory[id] = NULL;
	}
	else if (id < 4 && _Inventory[id])
		std::cout << "The floor is full" << std::endl;
	else
		std::cout << "Item not found" << std::endl;
}

AMateria	*Inventory::getItem(int id) {
	if (0 <= id && id < 4 && _Inventory[id])
		return _Inventory[id];
	return 0;
}