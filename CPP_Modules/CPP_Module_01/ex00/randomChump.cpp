#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombTmp(name);
	zombTmp.announce();
}