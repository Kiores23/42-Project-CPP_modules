#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main()
{
	std::cout << "[Test 0] Test subject : MutantStack" << std::endl << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl << "[Test 0] Test subject : List" << std::endl << std::endl;
	{
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(list);
	}
	std::cout << std::endl << "[Test 1] My test : base" << std::endl << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 1; i <= 5; i++)
			mstack.push(i);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		for (int i = 1; it != ite; i++)
		{
			std::cout << *it << std::endl;
			*it = 6 - i;
			++it;
		}
		std::cout << std::endl << "[Test 2] base : Change value" << std::endl << std::endl; 
		it = mstack.begin();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl << "[Test 3] My test : reverse" << std::endl << std::endl;
	{
		MutantStack<int> mstack;
		for (int i = 1; i <= 5; i++)
			mstack.push(i);
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		for (int i = 1; it != ite; i++)
		{
			std::cout << *it << std::endl;
			*it = i;
			++it;
		}
		std::cout << std::endl << "[Test 4] reverse : Change value" << std::endl << std::endl; 
		it = mstack.rbegin();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	return 0;
}