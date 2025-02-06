#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	malphite("Malphite");
	for (int i = 0; i < 26; i++)
	{
		malphite.attack("Bob");
		malphite.beRepaired(1);
	}
	malphite.whoAmI();
	return 0;
}