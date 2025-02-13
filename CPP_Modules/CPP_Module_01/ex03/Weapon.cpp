#include "Weapon.hpp"

Weapon::Weapon() {
	_type = "fist";
}

Weapon::Weapon(std::string type) {
	_type = type;
}

Weapon::~Weapon() {}

void	Weapon::setType(std::string type) {
	_type = type;
}

const std::string&	Weapon::getType() {
	return _type;
}
