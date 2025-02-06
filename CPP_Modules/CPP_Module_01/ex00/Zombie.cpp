#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
};

Zombie::~Zombie() {
	std::cout << _name << " is dead. (once again)" << std::endl;
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
