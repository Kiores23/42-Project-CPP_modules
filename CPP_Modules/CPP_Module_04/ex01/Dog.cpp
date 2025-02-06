#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	_Brain = new Brain;
	std::cout << "Dog was created." << std::endl;
}

Dog::Dog(const Dog& other) : Animal("Dog") {
	*this = other;
	std::cout << "Dog was copied." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		_Type = other._Type;
		*_Brain = *other._Brain;
	}
	std::cout << "Dog was copied." << std::endl;
	return *this;
}

Dog::~Dog() {
	delete _Brain;
	std::cout << "Dog was destroyed." << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Ouaf ouaf" << std::endl;
}

void	Dog::insertIdeas(std::string ideas, int id) {
	_Brain->setIdeas(ideas, id);
}

void	Dog::printIdeas(int id) {
	std::cout << _Brain->getIdeas(id) << std::endl;
}
