#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &other) : AMateria("ice") {
	*this = other;
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other)
		_Type = other._Type;
	return *this;
}

Ice::~Ice() {}

Ice* Ice::clone() const {
	Ice*	clone = new Ice;
	return clone;
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}