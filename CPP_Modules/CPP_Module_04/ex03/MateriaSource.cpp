#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource& other) {
	*this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other)
		_Memory = other._Memory;
	return *this;
}

MateriaSource::~MateriaSource() {}

void	MateriaSource::learnMateria(AMateria* m) {
	_Memory.setItem(m);
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	int	i;

	for (i = 0; i < 4 && _Memory.getItem(i) && _Memory.getItem(i)->getType() != type; i++)
		;
	if (i != 4 && _Memory.getItem(i))
		return _Memory.getItem(i)->clone();
	return 0;
}