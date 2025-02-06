#include "Animal.hpp"

Animal::Animal() : _Type("Species unknown") {
	std::cout << "Animal was created." << std::endl;
}

Animal::Animal(std::string type) : _Type(type) {
	std::cout << "Animal was created." << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Animal was copied." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		_Type = other._Type;
	std::cout << "Animal was copied." << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal was destroyed." << std::endl;
}

void	Animal::makeSound() const {
	if (_Type == "Species unknown")
		std::cout << "Sound of an unknown species." << std::endl;
	else
		std::cout << "Sound of a " << _Type << "." << std::endl;
}

std::string	Animal::getType() const {
	return _Type;
}