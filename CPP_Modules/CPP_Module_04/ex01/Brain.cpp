#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain was created." << std::endl; 
}

Brain::Brain(const Brain& other) {
	*this = other;
	std::cout << "Brain was copied." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain was copied." << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain was destroyed." << std::endl; 
}

void	Brain::setIdeas(std::string ideas, int id) {
	_ideas[id] = ideas;
}

std::string	Brain::getIdeas(int id) {
	return _ideas[id];
}
