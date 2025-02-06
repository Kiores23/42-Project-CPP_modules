#include "AAnimal.hpp"

AAnimal::AAnimal() : _Type("Species unknown") {
	std::cout << "AAnimal was created." << std::endl;
}

AAnimal::AAnimal(std::string type) : _Type(type) {
	std::cout << "AAnimal was created." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	*this = other;
	std::cout << "AAnimal was copied." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other)
		_Type = other._Type;
	std::cout << "AAnimal was copied." << std::endl;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal was destroyed." << std::endl;
}

void	AAnimal::makeSound() const {
	if (_Type == "Species unknown")
		std::cout << "Sound of an unknown species." << std::endl;
	else
		std::cout << "Sound of a " << _Type << "." << std::endl;
}

std::string	AAnimal::getType() const {
	return _Type;
}