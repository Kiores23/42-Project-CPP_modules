#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap	random;
	ClapTrap	bob("Bob");
	ClapTrap	marvin("Marvin");

	for (int i = 0; i < 10; i++)
	{
		bob.attack(marvin.getTarget());
		marvin.takeDamage(bob.getAttackDamage());
	}
	marvin.attack(bob.getTarget());
	bob.takeDamage(marvin.getAttackDamage());

	bob.attack(marvin.getTarget());
	for (int i = 0; i < 5; i++)
		marvin.beRepaired(1);
	random = marvin;
	for (int i = 0; i < 6; i++)
	{
		random.attack(bob.getTarget());
		bob.takeDamage(random.getAttackDamage());
	}
	return 0;
}