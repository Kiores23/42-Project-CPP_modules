#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat was created." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal("WrongCat") {
	*this = other;
	std::cout << "WrongCat was copied." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		_Type = "WrongCat";
	std::cout << "WrongCat was copied." << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat was destroyed." << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "[Wrong] Miaou miaou" << std::endl;
}