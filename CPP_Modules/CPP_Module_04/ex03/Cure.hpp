#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &other);
		Cure& operator=(const Cure& other);
		~Cure();

		Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif