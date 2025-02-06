#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog was created." << std::endl;
}

Dog::Dog(const Dog& other) : Animal("Dog") {
	*this = other;
	std::cout << "Dog was copied." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		_Type = "Dog";
	std::cout << "Dog was copied." << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog was destroyed." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Ouaf ouaf" << std::endl;
}
