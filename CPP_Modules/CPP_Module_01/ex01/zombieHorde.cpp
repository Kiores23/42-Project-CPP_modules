#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*firstZomb;

	firstZomb = new Zombie[N];
	for (int i = 0; i < N; i++)
		firstZomb[i].set_name(name);
	return firstZomb;
}