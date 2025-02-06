#include "Span.hpp"

int	main()
{
	std::cout << "[Test 0] Test subject" << std::endl << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl << "[Test 1] Exeption" << std::endl << std::endl;
	{
		Span sp = Span(1);
		sp.addNumber(6);
		try { sp.addNumber(3); }
		catch (const std::exception& e) { std::cerr << "exception: " << e.what() << std::endl; }
		try { sp.longestSpan(); }
		catch (const std::exception& e) { std::cerr << "exception: " << e.what() << std::endl; }
	}
	std::cout << std::endl << "[Test 2] Add range (1/2)" << std::endl << std::endl;
	{
		Span sp = Span(4);
		int range[3] = {3, -5, 30};
		sp.addNumber(0);
		sp.addRangeNumber(range, 3);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl << "[Test 2] Add range (2/2)" << std::endl << std::endl;
	{
		Span sp = Span(100);
		int range[] = {-92, -10, -5, 67, -74, -39, -26, -57, 97, 34, 14, -80, -15, 44, 20, -11, 59,\
						53, 36, -71, 75, 28, 46, 55, 83, -41, -38, -73, -29, -43, -84, -44, -68, 66,\
						69, 50, -56, -86, -31, -35, 71, 78, -55, -95, -62, 12, -20, -45, 61, -18, -76,\
						-17, 11, 70, 65, -37, 90, -16, -14, -46, -9, -40, -49, 48, 72, 89, 76, -72,\
						-70, -30, 99, -3, 27, -67, -59, -98, -69, -83, 45, 26, -61, -25, -64, -23, 32,\
						-47, -1, -77, 21, -28, -79, -81, 68, -63, 2, -88, -96, 8, -2, 15, -27, 23, -52,\
						-60, 30, -75, -65, 17, 42, -4, 22, -51};
		sp.addRangeNumber(range, 100);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}