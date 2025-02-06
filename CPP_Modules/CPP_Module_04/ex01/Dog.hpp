#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class	Dog : public Animal
{
	private:
		Brain*	_Brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void	makeSound() const;
		void	insertIdeas(std::string ideas, int id);
		void	printIdeas(int id);
};

#endif