#include <iostream>
#include <cstdlib>
#include <limits>

int	parsingConvert(std::string str) {
	if (!str.c_str())
		return 1;
	else if (str == "nan" || str == "nanf" || str == "inf"
		|| str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return 0;
	else if (isprint(str[0]) && !isdigit(str[0]) && str[1]
		&& ((str[0] != '+' && str[0] != '-') || !isdigit(str[1]))) {
		std::cerr << "Error: String detected" << std::endl;
		return 1;
	}
	else if (isprint(str[0]) && !isdigit(str[0]) && !str[1])
		return 0;
	for (int i = 0; str[i]; i++)
	{
		if ((str[0] == '+' || str[0] == '-') && i == 0)
			i++;
		if ((!isdigit(str[i]) && str[i] != 'f' && str[i] != '.')
			|| (!isdigit(str[i]) && str[i] != 'f' && !str[i + 1])
			|| (str[i] == 'f' && (i < 2 || str[i - 2] != '.'))
			|| (str[i] == '.' && str[i + 1] && str[i + 2] && str[i + 2] != 'f')) {
			std::cerr << "Error: String detected" << std::endl;
			return 1;
		}
	}
	return 0;
}

int	checkOverflow(std::string unit) {
	if ((std::numeric_limits<int>::min() > atof(unit.c_str())
		|| atof(unit.c_str()) > std::numeric_limits<int>::max()))
		return 1;
	return 0;
}

void	convertToChar(std::string unit) {
	int		unitInt = atoi(unit.c_str());
	char	unitChar = static_cast<char>(unitInt % 128);

	if (unitInt < 0 || unit == "nan" || unit == "nanf" || unit == "inf"
		|| unit == "+inf" || unit == "+inff" || unit == "-inf" || unit == "-inff")
		std::cout << "char: impossible" << std::endl;
	else if (isprint(unit[0]) && !isdigit(unit[0]) && ((unit[0] != '-' && unit[0] != '+') || !unit[1]))
		std::cout << "char: \'" << unit[0] << "\'" << std::endl;
	else if ((isdigit(unit[0]) || (unit[0] && isdigit(unit[1]))) && isprint(unitChar))
		std::cout << "char: \'" << unitChar << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	convertToInt(std::string unit) {
	int		unitInt = atoi(unit.c_str());

	if (isprint(unit[0]) && !isdigit(unit[0]) && !unit[1]) {
		unitInt = static_cast<int>(unit[0]);
	}
	if (checkOverflow(unit) || unit == "nan" || unit == "nanf" || unit == "inf"
		|| unit == "+inf" || unit == "+inff" || unit == "-inf" || unit == "-inff")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << unitInt << std::endl;
}

void	convertToFloat(std::string unit) {
	float	unitInt = atol(unit.c_str());
	float	unitFloat = static_cast<float>(atof(unit.c_str()));

	if (isprint(unit[0]) && !isdigit(unit[0]) && !unit[1]) {
		unitInt = static_cast<int>(unit[0]);
		unitFloat = static_cast<float>(unit[0]);
	}
	std::cout << "float: " << unitFloat;
	if ((unitFloat >= -99999 && unitFloat <= 99999) && static_cast<float>(unitInt) == unitFloat)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	convertToDouble(std::string unit) {
	double	unitInt = atol(unit.c_str());
	double	unitDouble = atof(unit.c_str());

	if (isprint(unit[0]) && !isdigit(unit[0]) && !unit[1]) {
		unitInt = static_cast<int>(unit[0]);
		unitDouble = static_cast<double>(unit[0]);
	}
	std::cout << "double: " << unitDouble;
	if ((unitDouble >= -99999 && unitDouble <= 99999) && static_cast<double>(unitInt) == unitDouble)
		std::cout << ".0";
	std::cout << std::endl;
}