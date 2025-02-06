#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

# define tT typename T

template <typename T>
tT::iterator	easyfind(T & arg1, int n) {
	tT::iterator it = std::find(arg1.begin(), arg1.end(), n);
	if (it == arg1.end()) throw std::runtime_error("Occurrence not found in container.");
	return it;
}

#endif