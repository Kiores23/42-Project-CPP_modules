#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	//Base test
	{
		void*	animals[50];

		for (int i = 0; i < 20; i++)
			animals[i] = new Cat;
		for (int i = 20; i < 40; i++)
			animals[i] = new Dog;
		std::cout << std::endl;
		for (int i = 0; i < 40; i++)
			delete (AAnimal *)animals[i];
		std::cout << std::endl;
	}
	// Brain test
	{
		Cat	*miaous = new Cat;
		Cat	*persian = new Cat;

		std::cout << std::endl;
		for (int i = 0; i < 100; i++)
			miaous->insertIdeas("Just an idea", i);
		for (int i = 0; i < 100; i++) {
			std::cout << i << ": ";
			miaous->printIdeas(i);
		}
		std::cout << std::endl;
		*persian = *miaous;
		for (int i = 0; i < 100; i++) {
			std::cout << i << ": ";
			persian->printIdeas(i);
		}
		// Copy test
		miaous->insertIdeas("Wrong idea", 0);
		std::cout << std::endl << "miaous: ";
		miaous->printIdeas(0);
		std::cout << "persian: ";
		persian->printIdeas(0);
	
		std::cout << std::endl;
		delete miaous;
		delete persian;
	}
	return 0;
}