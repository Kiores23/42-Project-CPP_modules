#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("unknown"), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0){
	std::cout << "ClapTrap " << _Name << " was created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "ClapTrap " << _Name << " was created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "ClapTrap " << _Name << " was copied." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage; }
	std::cout << "ClapTrap " << _Name << " was copied." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _Name << " was destroyed." << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (!_HitPoints)
		std::cout << "ClapTrap " << _Name << " cannot attack because he has no more hit points." << std::endl;
	else if (!_EnergyPoints)
		std::cout << "ClapTrap " << _Name << " cannot attack because he has no more energy points." << std::endl;
	else { _EnergyPoints--;
		std::cout << "ClapTrap " << _Name << " attacks " << target << " causing " << _AttackDamage << " points of damage!" << std::endl; }
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (!_HitPoints) return ;
	if (amount > _HitPoints) { _HitPoints = 0; }
	else { _HitPoints -= amount; }
	if (!_HitPoints) { std::cout << "ClapTrap " << _Name << " has no more hit points." << std::endl; }
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (!_EnergyPoints)
		std::cout << "ClapTrap " << _Name << " cannot repair himself because he has no more energy points." << std::endl;
	else { _HitPoints += amount; _EnergyPoints--;
		std::cout << "ClapTrap " << _Name << " repairs " << amount << " hit points!" << std::endl; }
}

std::string	ClapTrap::getTarget() const{
	return _Name;
}

unsigned int	ClapTrap::getAttackDamage() const{
	return _AttackDamage;
}
