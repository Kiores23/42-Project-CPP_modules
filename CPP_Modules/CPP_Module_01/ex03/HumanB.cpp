#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void    HumanB::attack() {
    if ((*_weapon).getType() != "")
        std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
    else
        std::cout << _name << " doesn't have a weapon" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
    _weapon = &weapon;
}