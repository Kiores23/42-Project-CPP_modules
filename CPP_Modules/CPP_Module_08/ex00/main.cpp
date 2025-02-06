#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

int	main(void)
{
	std::cout << std::endl << "[Test 1] List" << std::endl << std::endl;

	{
		std::list<int>	a;
		a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
		
		std::list<int>::iterator	it, end; end = a.end();

		for (it = a.begin(); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 1); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 3); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 4); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		try {
			for (it = easyfind(a, 5); it != end; it++)
				std::cout << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "[Test 2] Vector" << std::endl << std::endl;
	{
		std::vector<int>	a;
		a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
		
		std::vector<int>::iterator	it, end; end = a.end();

		for (it = a.begin(); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 1); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 3); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 4); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		try {
			for (it = easyfind(a, 5); it != end; it++)
				std::cout << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "[Test 3] Deque" << std::endl << std::endl;
	{
		std::deque<int>	a;
		a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
		
		std::deque<int>::iterator	it, end; end = a.end();

		for (it = a.begin(); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 1); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 3); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		for (it = easyfind(a, 4); it != end; it++)
			std::cout << *it << std::endl;
		std::cout << std::endl;
		try {
			for (it = easyfind(a, 5); it != end; it++)
				std::cout << *it << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
}