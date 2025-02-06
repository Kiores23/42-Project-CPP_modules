#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_guardGate = 0;
	std::cout << "ScavTrap " << _Name << " was created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_guardGate = 0;
	std::cout << "ScavTrap " << _Name << " was created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "ScavTrap " << _Name << " was copied." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
		_guardGate = other._guardGate; }
	std::cout << "ScavTrap " << _Name << " was copied." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _Name << " was destroyed." << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (!_HitPoints)
		std::cout << "ScavTrap " << _Name << " cannot attack because he has no more hit points." << std::endl;
	else if (!_EnergyPoints)
		std::cout << "ScavTrap " << _Name << " cannot attack because he has no more energy points." << std::endl;
	else { _EnergyPoints--;
		std::cout << "ScavTrap " << _Name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl; }
}

void	ScavTrap::guardGate() {
	if (!_guardGate) {
		std::cout << "ScavTrap " << _Name << " activates gate guardian mode." << std::endl;
		_guardGate = 1;
	}
	else {
		std::cout << "ScavTrap " << _Name << " disables gate guardian mode." << std::endl;
		_guardGate = 0;
	}
}
