#include <iostream>
#include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
	ClapTrap	bob("bob");
	ScavTrap	galio("Galio");

	galio.attack(bob.getTarget());
	bob.takeDamage(galio.getAttackDamage());
	galio.guardGate();
	galio.guardGate();
	galio.beRepaired(1);
	return 0;
}