#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>

class PmergeMe {
	private:
		std::vector<int>	_Vector;
		std::list<int>		_List;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe & other);
		~PmergeMe();
		PmergeMe & operator=(const PmergeMe & other);

		int	printandsort(char ** tab);
};

#endif