#include "Array.hpp"

int	main(void)
{
	std::cout << "[Test 1] Basic init" << std::endl;
	Array<int>	a(2);
	Array<std::string>	b(2);
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "]: " << a[0] << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "]: " << b[0] << std::endl;
	std::cout << std::endl;
	/////////////////////////////////////////////////
	std::cout << "[Test 2] Set value" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = 3;
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = "Hey";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "]: " << a[0] << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "]: " << b[0] << std::endl;
	std::cout << std::endl;
	/////////////////////////////////////////////////
	std::cout << "[Test 3] Copy" << std::endl;
	Array<int>	c(a);
	Array<std::string>	d = b;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << "c[" << i << "]: " << c[0] << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << "d[" << i << "]: " << d[0] << std::endl;
	std::cout << std::endl;
	/////////////////////////////////////////////////
	std::cout << "[Test 4] After copy" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = 6;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "a[" << i << "]: " << a[0] << std::endl;
	std::cout << std::endl;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << "c[" << i << "]: " << c[0] << std::endl;
	std::cout << std::endl;
	/////////////////////////////////////////////////
	std::cout << "[Test 5] Exeption" << std::endl;
	try { std::cout << a[10] << std::endl; }
	catch (const std::exception& e) {std::cout << "exception: "<< e.what() << std::endl; }
	try { Array<int> e(0); std::cout << e[0]; }
	catch (const std::exception& e) {std::cout << "exception: "<< e.what() << std::endl << std::endl;}
	/////////////////////////////////////////////////
	std::cout << "[Test 6] Size()" << std::endl;
	Array<int>	e(0), f(10);
	std::cout << "a: " << a.size() << ", b:" << b.size() << ", c:" << c.size() \
		<< ", d:" << d.size() << ", e:" << e.size() << ", f:" << f.size() << std::endl;
	return 0;
}
