#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _Name(name) {
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	_Grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_Grade = other._Grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const {
	return _Name;
}

int Bureaucrat::getGrade() const {
	return _Grade;
}

void	Bureaucrat::promotion() {
	if (_Grade + 1 > 150)
		throw GradeTooHighException();
	_Grade++;
}

void	Bureaucrat::demotion() {
	if (_Grade - 1 < 1)
		throw GradeTooLowException();
	_Grade--;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
			return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
			return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrate grade " << bureaucrat.getGrade();
	return os;
}