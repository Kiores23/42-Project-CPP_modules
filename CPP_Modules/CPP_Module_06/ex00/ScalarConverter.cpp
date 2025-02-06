#include "ScalarConverter.hpp"

int		parsingConvert(std::string str);
void	convertToChar(std::string unit);
void	convertToInt(std::string unit);
void	convertToFloat(std::string unit);
void	convertToDouble(std::string unit);

ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other) {
		;
	}
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string unit) {
	if (parsingConvert(unit))
		return ;
	convertToChar(unit);
	convertToInt(unit);
	convertToFloat(unit);
	convertToDouble(unit);
}