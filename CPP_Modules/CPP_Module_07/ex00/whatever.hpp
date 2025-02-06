#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T& arg1, T& arg2) {
	T tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template <typename T>
const T& min(const T& arg1, const T& arg2) {
	return (arg1 < arg2) ? arg1 : arg2;
}

template <typename T>
const T& max(const T& arg1, const T& arg2) {
	return (arg1 > arg2) ? arg1 : arg2;
}

#endif