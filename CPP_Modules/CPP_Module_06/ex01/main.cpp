#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data*	a = new Data;
	
	std::cout << "Original pointer :\t" << a << std::endl; 
	std::cout << "Converted pointer :\t" << Serializer::serialize(a) << std::endl;
	std::cout << "Reconverted pointer :\t" << Serializer::deserialize(Serializer::serialize(a)) << std::endl;
	if (a) delete a;
	return 0;
}