#include "Bureaucrat.hpp"

int	main()
{
	// [Test 1]
	try {
		Bureaucrat brunos("Brunos", 50);
		std::cout << "[Test 1] " << brunos << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 1] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 2]
	try {
		Bureaucrat harry("Harry", 0);
		std::cout << "[Test 2] " << harry << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 2] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 3]
	try {
		Bureaucrat mathieu("Mathieu", 151);
		std::cout << "[Test 3] " << mathieu << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 3] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 4]
	try {
		Bureaucrat damien("Damien", 2);
		std::cout << "[Test 4] " << damien << std::endl;
		damien.demotion();
		std::cout << "[Test 4] " << damien << std::endl;
		damien.demotion();
		std::cout << "[Test 4] " << damien << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 4] An exception occurred: " << e.what() << std::endl;
	}
	// [Test 5]
	try {
		Bureaucrat nevil("Nevil", 150);
		std::cout << "[Test 5] " << nevil << std::endl;
		nevil.promotion();
		std::cout << "[Test 5] " << nevil << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "[Test 5] An exception occurred: " << e.what() << std::endl;
	}
	return 0;
}