#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T* tab, const int size, void (*f)(T &)) {
	for (int i = 0; i < size; i++)
		f(tab[i]);
}

template <typename T>
void	iter(T* tab, const int size, void (*f)(const T &)) {
	for (int i = 0; i < size; i++)
		f(tab[i]);
}

template <typename T>
void	printTemplate(T & arg) {
	std::cout << arg << std::endl;
}

template <typename T>
void	setTemplateToZero(T & arg) {
	arg = T();
}

#endif