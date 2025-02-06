#include "AMateria.hpp"

AMateria::AMateria() : _Type("Default") {}

AMateria::AMateria(std::string const & type) : _Type(type) {}

AMateria::AMateria(AMateria const &other) {
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other)
		_Type = other._Type;
	return *this;
}

AMateria::~AMateria() {}

std::string const &	AMateria::getType() const {
	return _Type;
}

void	AMateria::use(ICharacter& target) { (void)target; }
