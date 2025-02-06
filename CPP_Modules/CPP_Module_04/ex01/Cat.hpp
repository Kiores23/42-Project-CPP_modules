#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class	Cat : public Animal
{
	private:
		Brain*	_Brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void	makeSound() const;
		void	insertIdeas(std::string ideas, int id);
		void	printIdeas(int id);
};

#endif