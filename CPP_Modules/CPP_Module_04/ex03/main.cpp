#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int	main()
{
	//Base test
	std::cout << "----------Base test----------" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	//All test
	std::cout << std::endl << "----------All test----------" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(10, *bob);
		me->use(-1, *bob);
		tmp = src->createMateria("cure");
		src->learnMateria(new Cure());
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(1, *bob);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->unequip(1);
		me->use(1, *bob);
		me->unequip(1);
		me->use(1, *bob);
		me->equip(tmp);
		
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
		me->use(3, *bob);
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}