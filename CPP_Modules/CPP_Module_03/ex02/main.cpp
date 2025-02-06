#include <iostream>
#include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
	ClapTrap	bob("bob");
	ScavTrap	galio("Galio");
	ScavTrap	powerTmp("Galio 2.0");
	FragTrap	bard("Bard");

	galio.attack(bob.getTarget());
	bob.takeDamage(galio.getAttackDamage());
	galio.guardGate();
	galio.guardGate();
	for (int i = 0; i < 4; i++)
	{
		bard.attack(galio.getTarget());
		galio.takeDamage(bard.getAttackDamage());
		galio.attack(bard.getTarget());
		bard.takeDamage(galio.getAttackDamage());
	}
	bard.highFivesGuys();
	galio = powerTmp;
	galio.attack(bard.getTarget());
	bard.takeDamage(galio.getAttackDamage());
	return 0;
}