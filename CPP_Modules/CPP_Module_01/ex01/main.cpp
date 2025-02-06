#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*horde;
	horde = zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	horde = zombieHorde(15, "Ivan");
	for (int i = 0; i < 15; i++)
		horde[i].announce();
	delete [] horde;
	horde = zombieHorde(1, "Avan");
	for (int i = 0; i < 1; i++)
		horde[i].announce();
	delete [] horde;
	horde = zombieHorde(0, "Alexis");
	for (int i = 0; i < 0; i++)
		horde[i].announce();
	delete [] horde;
	return 0;
}