#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

using std::vector;

class Span : public vector<int>
{
	private:
		unsigned int _Capacity;

	public:
		Span();
		Span(unsigned int size);
		Span(const Span & other);
		Span & operator=(const Span & other);
		~Span();
	
		void			addNumber(int n);
		void			addRangeNumber(int *range, int size);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};

class SpanOverflow : public std::exception {
	public:
		virtual const char* what() const throw();
};
	
class SpanError : public std::exception {
	public:
		virtual const char* what() const throw();
};

#endif