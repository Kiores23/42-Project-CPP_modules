#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class	Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void		setIdeas(std::string ideas, int id);
		std::string	getIdeas(int id);
};

#endif