#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << _Name << " was created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << _Name << " was created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap " << _Name << " was copied." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage; }
	std::cout << "FragTrap " << _Name << " was copied." << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _Name << " was destroyed." << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _Name << " performs a magnificent high five." << std::endl;
}
