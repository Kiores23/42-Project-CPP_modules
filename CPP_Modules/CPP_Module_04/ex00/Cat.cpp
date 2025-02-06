#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat was created." << std::endl;
}

Cat::Cat(const Cat& other) : Animal("Cat") {
	*this = other;
	std::cout << "Cat was copied." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		_Type = "Cat";
	std::cout << "Cat was copied." << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat was destroyed." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miaou miaou" << std::endl;
}