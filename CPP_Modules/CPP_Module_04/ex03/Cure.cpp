#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria("cure") {
	*this = other;
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other)
		_Type = other._Type;
	return *this;
}

Cure::~Cure() {}

Cure* Cure::clone() const {
	Cure*	clone = new Cure;
	return clone;
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}