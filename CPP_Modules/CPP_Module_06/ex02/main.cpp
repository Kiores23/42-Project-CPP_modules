#include "Base.hpp"
#include <iostream>

int	main()
{
	Base* base = Base::generate();
	std::cout << "identify * :";
	Base::identify(base);
	std::cout << "identify & :";
	Base::identify(*base);
	delete base;
	return 0;
}