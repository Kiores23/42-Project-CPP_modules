#include "PmergeMe.hpp"
#include <cstdlib>
#include <algorithm>
#include <ctime>

template <typename T>
typename T::iterator incrIt(typename T::iterator it, int n)
{
	for (int i = 0; i < n; i++)
		it++;
	for (int i = 0; i > n; i--)
		it--;
	return it;
}

template <typename T>
void insertSort(T &array) {
	for (typename T::iterator it = array.begin(); it != array.end(); ++it)
    {
        int k = *it;
        typename T::iterator itr = it;
        while (itr != array.begin() && k < *(incrIt<T>(itr, -1)))
        {
            --itr;
            *(incrIt<T>(itr, 1)) = *itr; 
        }
        *itr = k;
    }
}

template <typename T>
T	merge(T & leftArray, T & rightArray)
{
	T array;

    typename T::const_iterator leftIt = leftArray.begin();
    typename T::const_iterator rightIt = rightArray.begin();

    while (leftIt != leftArray.end() || rightIt != rightArray.end())
    {
        if (rightIt == rightArray.end() || (leftIt != leftArray.end() && *leftIt < *rightIt))
        {
            array.push_back(*leftIt);
            ++leftIt;
        }
        else
        {
            array.push_back(*rightIt);
            ++rightIt;
        }
    }
    return array;
}

template <typename T>
T &	mergeInsertSort(T & array)
{
	int n = array.size();
    if (n <= 5)
        insertSort(array);
    else
    {
        T leftArray(array.begin(), incrIt<T>(array.begin(), n / 2));
        T rightArray(incrIt<T>(array.begin(), n / 2), array.end());
        mergeInsertSort(leftArray);
        mergeInsertSort(rightArray);
        array = merge(leftArray, rightArray);
    }
	return array;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe & other)
{
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=(const PmergeMe & other)
{
	if (this != &other)
	{
		_List = other._List;
		_Vector = other._Vector;
	}
	return *this;
}

int	PmergeMe::printandsort(char ** tab) 
{
	try {
		for (int i = 0; tab[i]; i++)
		{
			for (int j = 0; tab[i][j]; j++)
			{
				if (!std::isdigit(tab[i][j]))
					throw std::runtime_error("Error: Wrong char");
			}
			_Vector.push_back(std::atoi(tab[i]));
			_List.push_back(std::atoi(tab[i]));
			if (_Vector.back() < 0)
				throw std::runtime_error("Error: Int overflow");
		}
	}
	catch (const std::runtime_error & e) 
	{
		_Vector.clear();
		_List.clear();
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::list<int>::iterator	ite = _List.end();
	std::cout << "Before:\t";
	for (std::list<int>::iterator it = _List.begin(); it != ite; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	clock_t t1 = clock();
	mergeInsertSort(_List);
	clock_t t2 = clock();
	mergeInsertSort(_Vector);
	clock_t t3 = clock();
	std::cout << "After:\t";
	for (std::list<int>::iterator it = _List.begin(); it != ite; it++)
		std::cout << " " << *it;
	std::cout << std::endl;
	double listTime = (static_cast<double>(t2 - t1) / CLOCKS_PER_SEC) * 1e+6;
	double vectorTime = (static_cast<double>(t3 - t2) / CLOCKS_PER_SEC) * 1e+6;
	std::cout << "Time to process a range of " << _List.size()
		<< " elements with std::list : " << listTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _Vector.size()
		<< " elements with std::vector : " << vectorTime << " us" << std::endl;
	_Vector.clear();
	_List.clear();
	return 0;
}
