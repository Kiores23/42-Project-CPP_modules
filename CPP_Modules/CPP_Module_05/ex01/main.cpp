#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	noob("Noob", 125);
	Bureaucrat	pro("Pro", 25);
	
	// [Test 1]
	try {
		Form test("Test", 151, 50);
		std::cout << "[Test 1] " << test << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 1] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 2]
	try {
		Form test("Test", 50, 0);
		std::cout << "[Test 2] " << test << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 2] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 3]
	try {
		Form test("Test", 150, 150);
		std::cout << "[Test 3] " << test << std::endl << std::endl;
		noob.signForm(test);
		std::cout << std::endl << "[Test 3] " << test << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 3] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 4]
	try {
		Form test("Test", 75, 75);
		std::cout << "[Test 4] " << test << std::endl << std::endl;
		noob.signForm(test);
		pro.signForm(test);
		pro.signForm(test);
		std::cout << std::endl << "[Test 4] " << test << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 4] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 5]
	try {
		Form test("Test", 1, 1);
		std::cout << "[Test 5] " << test << std::endl;
		test.beSigned(pro);
		std::cout << std::endl << "[Test 5] " << test << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 5] An exception occurred: " << e.what() << std::endl;
	}
	return 0;
}