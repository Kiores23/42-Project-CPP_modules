#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: Number of arguments" << std::endl;
		return 1;
	}
	PmergeMe pmergeme;
	if (pmergeme.printandsort(&argv[1]))
		return 1;
	return 0;
}