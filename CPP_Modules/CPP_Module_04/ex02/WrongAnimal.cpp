#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _Type("Species unknown") {
	std::cout << "WrongAnimal was created." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _Type(type) {
	std::cout << "WrongAnimal was created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cout << "WrongAnimal was copied." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		_Type = other._Type;
	std::cout << "WrongAnimal was copied." << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal was destroyed." << std::endl;
}

void	WrongAnimal::makeSound() const {
	if (_Type == "Species unknown")
		std::cout << "[Wrong] Sound of an unknown species." << std::endl;
	else
		std::cout << "[Wrong] Sound of a " << _Type << "." << std::endl;
}

std::string	WrongAnimal::getType() const {
	return _Type;
}