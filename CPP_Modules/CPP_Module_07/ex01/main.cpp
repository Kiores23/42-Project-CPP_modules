#include "iter.hpp"

int	main(void)
{
	void	(*printInt)(int &) = printTemplate;
	void	(*printString)(std::string &) = printTemplate;
	void	(*setIntToZero)(int &) = setTemplateToZero;
	void	(*setStringToZero)(std::string &) = setTemplateToZero;

	int				size = 5;
	int*			tabInt = new int[size];
	std::string*	tabString = new std::string[size];

	iter(tabInt, size, setIntToZero);
	iter(tabString, size, setStringToZero);
	std::cout << "[Test 1] Int = Init" << std::endl;
	iter(tabInt, size, printInt);
	std::cout << std::endl << "[Test 1] String = Init" << std::endl;
	iter(tabString, size, printString);
	for (int i = 0; i < size; i++) {
		tabInt[i] = i;
		tabString[i] = i + 65;
	}
	std::cout << std::endl << "[Test 2] Int = With Value" << std::endl;
	iter(tabInt, size, printInt);
	std::cout << std::endl << "[Test 2] String = With Value" << std::endl;
	iter(tabString, size, printString);
	iter(tabInt, size, setIntToZero);
	iter(tabString, size, setStringToZero);
	std::cout << std::endl << "[Test 3] Int = To Zero" << std::endl;
	iter(tabInt, size, printInt);
	std::cout << std::endl << "[Test 3] String = To Zero" << std::endl;
	iter(tabString, size, printString);

	delete [] tabInt;
	delete [] tabString;
	return 0;
}