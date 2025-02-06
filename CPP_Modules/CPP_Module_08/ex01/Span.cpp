#include "Span.hpp"
#include "algorithm"

Span::Span() : vector<int>(0), _Capacity(0) {}

Span::Span(unsigned int size) : vector<int>(0), _Capacity(size) {}

Span::Span(const Span & other) : vector<int>(other), _Capacity(other._Capacity) {}

Span & Span::operator=(const Span & other) {
	if (this != &other)
	{
        std::vector<int>::operator=(other);
		_Capacity = other._Capacity;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int n) {
	if (this->size() >= _Capacity) throw SpanOverflow();
	this->push_back(n);
}

void	Span::addRangeNumber(int *range, int size) {
	for (int i = 0; i < size; i++)
		addNumber(range[i]);
}

unsigned int	Span::shortestSpan() {
	if (this->size() <= 1) throw SpanError();
	unsigned int	shortestSpan;
	Span	tmp = *this;
	std::sort(tmp.begin(), tmp.end());
	shortestSpan = std::max(*tmp.begin(), *(tmp.begin() + 1)) - std::min(*tmp.begin(), *(tmp.begin() + 1));
	for (Span::iterator it = tmp.begin(); it + 1 != tmp.end(); it++)
		shortestSpan = std::min(shortestSpan, static_cast<unsigned int>(std::max(*it, *(it + 1)) - std::min(*it, *(it + 1))));
	return shortestSpan;
}

unsigned int	Span::longestSpan() {
	if (this->size() <= 1) throw SpanError();
	return *std::max_element(this->begin(), this->end()) - *std::min_element(this->begin(), this->end());
}

const char* SpanOverflow::what() const throw() {
			return "Span overflow";
}

const char* SpanError::what() const throw() {
			return "Span error";
}