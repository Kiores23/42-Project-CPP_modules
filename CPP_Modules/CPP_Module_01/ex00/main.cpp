#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	int			i;
	std::string	name;
	Zombie*		zTab[10];
	Zombie		z1("Thomas");

	z1.announce();
	randomChump("Pedro");
	i = -1;
	while (++i < 10)
	{
		zTab[i] = newZombie("Zombie");
		zTab[i]->announce();
	}
	i = -1;
	while (++i < 10)
		delete zTab[i];
	return 0;
}