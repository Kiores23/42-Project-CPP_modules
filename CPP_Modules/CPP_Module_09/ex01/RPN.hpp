#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class	RPN {
	private:
		std::stack<float>	_Stack;
		void	operation(char s);
	public:
		RPN();
		RPN(const RPN & other);
		~RPN();
		RPN & operator=(const RPN & other);

		float	calculation(char * tab);
};

#endif