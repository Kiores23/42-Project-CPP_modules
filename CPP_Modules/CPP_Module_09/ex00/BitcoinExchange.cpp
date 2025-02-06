#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>

bool dateIsTrue(int d, int m, int y);

Btc::Btc() 
{
	std::ifstream   file;

	file.open("data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: data.csv: file not found");
	std::string	line;
	getline(file, line);
	if (line == "date,exchange_rate")
		getline(file, line);
	while (1)
	{
		if (!line.empty())
			addData(line);
		if (!getline(file, line))
			break;
	}
}

Btc::Btc(const Btc & other) 
{
	*this = other;
}

Btc::~Btc() {}

Btc & Btc::operator=(const Btc & other)
{
	if (this != &other)
		_Data = other._Data;
	return *this;
}

void    Btc::addData(std::string & line) 
{
	if (line.size() < 12 || line[4] != '-' || line[7] != '-' || line[10] != ',')
		throw std::runtime_error("Error: data.csv: content");
	for (int i = 0; i < 12 && line[i]; i++)
	{
		if (i != 4 && i != 7 && i != 10 && !std::isdigit(line[i]))
			throw std::runtime_error("Error: data.csv: content");
	}
	for (int i = 12; line[i]; i++)
	{
		if (i == 12)
		{
			while (line[i] && line[i] != '.' && std::isdigit(line[i]))
				i++;
			if (line[i] == '.' && line[i + 1])
				i++;
		}
		if (line[i] && !std::isdigit(line[i]))
			throw std::runtime_error("Error: data.csv: content");
	}
	if (!dateIsTrue(std::atoi(&line[8]), std::atoi(&line[5]), std::atoi(&line[0])))
		throw std::runtime_error("Error: data.csv: invalid date");
	float	value = std::atof(&line[11]);

	_Data[line.substr(0, 10)] = value;
}

void Btc::BtcCheck(const std::string & fileName) 
{
	std::ifstream   file;

	file.open(fileName.c_str());
	if (!file.is_open())
	{
		std::string	strerror = "Error: " + fileName + ": file not found";
		throw std::runtime_error(strerror);
	}
	std::string	line;
	getline(file, line);
	if (line == "date | value")
		getline(file, line);
	while (1)
	{
		try {
			if (!line.empty())
				printInput(line);
		}
		catch (const std::runtime_error &e) {
			if (e.what() == line)
				std::cerr << "Error: bad input => " << e.what() << std::endl;
			else
				std::cerr << e.what() << std::endl;
		}
		if (!getline(file, line))
			break;
	}
}

void    Btc::printInput(std::string & line)
{
	if (line.size() < 14 || line[4] != '-' || line[7] != '-'
		|| line.substr(10, 3) != " | ")
		throw std::runtime_error(line);
	if (line[13] == '-' && std::isdigit(line[14]))
		throw std::runtime_error("Error: not a positive number.");
	for (int i = 0; i < 10 && line[i]; i++)
	{
		if (i != 4 && i != 7 && !std::isdigit(line[i]))
			throw std::runtime_error(line);
	}
	for (int i = 13; line[i]; i++)
	{
		if (i == 13)
		{
			while (line[i] && line[i] != '.' && std::isdigit(line[i]))
				i++;
			if (line[i] == '.' && line[i + 1])
				i++;
		}
		if (line[i] && !std::isdigit(line[i]))
			throw std::runtime_error(line);
	}
	if (!dateIsTrue(std::atoi(&line[8]), std::atoi(&line[5]), std::atoi(&line[0])))
		throw std::runtime_error("Error: invalid date");
	float	value = std::atof(&line[13]);
	if (value < 0 || value > 1000)
		throw std::runtime_error("Error: too large a number.");
	std::string								date = line.substr(0, 10);
	std::map<std::string, float>::iterator	it = _Data.lower_bound(date);
	if (it->first != date && it != _Data.begin())
		it--;
	else if (it->first != date)
		throw std::runtime_error("Error: no data");
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

bool dateIsTrue(int d, int m, int y) {
	if (m < 1 || m > 12 || d < 1)
		return false;

	int tm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
		tm[2] = 29;
	return (d <= tm[m]);
}