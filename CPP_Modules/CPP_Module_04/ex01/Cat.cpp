#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	_Brain = new Brain;
	std::cout << "Cat was created." << std::endl;
}

Cat::Cat(const Cat& other) : Animal("Cat") {
	*this = other;
	std::cout << "Cat was copied." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		_Type = other._Type;
		*_Brain = *other._Brain;
	}
	std::cout << "Cat was copied." << std::endl;
	return *this;
}

Cat::~Cat() {
	delete _Brain;
	std::cout << "Cat was destroyed." << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Miaou miaou" << std::endl;
}

void	Cat::insertIdeas(std::string ideas, int id) {
	_Brain->setIdeas(ideas, id);
}

void	Cat::printIdeas(int id) {
	std::cout << _Brain->getIdeas(id) << std::endl;
}