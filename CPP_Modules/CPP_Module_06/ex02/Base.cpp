#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <ctime>

Base::~Base() {}

Base*	Base::generate(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	switch (std::rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void	Base::identify(Base *p) {
	if (!p)
		std::cout << "Null" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "No type" << std::endl;
}

void	Base::identify(Base &p) {
	try{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e) {
	try{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch(std::exception &e) {
	try{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch(std::exception &e) {
		std::cout << "No type" << std::endl;
	}}}
}