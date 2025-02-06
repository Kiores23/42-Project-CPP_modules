#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & other)
{
	*this = other;
}

RPN::~RPN() {}

RPN &	RPN::operator=(const RPN & other)
{
	if (this != &other)
		_Stack = other._Stack;
	return *this;
}

float	RPN::calculation(char * tab)
{
	float	result;

	try
	{
		if (!tab)
			throw std::runtime_error("Error: char * tab => voidptr");
		for (int i = 0; tab[i]; i++)
		{
			if (tab[i] == ' ' && tab[i + 1] && tab[i + 1] != ' ')
				i++;
			if (std::isdigit(tab[i]))
				_Stack.push(tab[i] - 48);
			else if (tab[i] == '+' || tab[i] == '-' || tab[i] == '*' || tab[i] == '/')
				operation(tab[i]);
			else
				throw std::runtime_error("Error: wrong character found");
		}
		if (_Stack.size() != 1)
			throw std::runtime_error("Error: wrong calculation");
		result = _Stack.top();
		_Stack.pop();
	}
	catch (const std::runtime_error & e)
	{
		while (!_Stack.empty())
			_Stack.pop();
		throw std::runtime_error(e.what());
	}
	return result;
}

void	RPN::operation(char s)
{
	if (_Stack.size() < 2)
		throw std::runtime_error("Error");

	float	b = _Stack.top();
	_Stack.pop();
	float	a = _Stack.top();
	_Stack.pop();
	switch (s)
	{
		case '+':
			_Stack.push(a + b);
			break;
		case '-':
			_Stack.push(a - b);
			break;
		case '*':
			_Stack.push(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: divided by 0");
			_Stack.push(a / b);
			break;
	}
}