#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _Name("unknown") {
	_HitPoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 30;
	std::cout << "DiamondTrap " << _Name << " was created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _Name(name) {
	_HitPoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 30;
	std::cout << "DiamondTrap " << _Name << " was created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;
	std::cout << "DiamondTrap " << _Name << " was copied." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
		_guardGate = other._guardGate; }
	std::cout << "DiamondTrap " << _Name << " was copied." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _Name << " was destroyed." << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << _Name << " says : \"My ClapTrap name is " << ClapTrap::_Name << "\"." << std::endl;
}