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

void	Bureaucrat::signForm(AForm& form) {
	if (form.isSigned()) {
		std::cout << getName() << " couldn’t sign " << form.getName() << " because " << form.getName() << " is already signed" << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << getName() << " couldn’t sign " << form.getName() << " because : " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << getName() << " couldn’t execute " << form.getName() << " because : " << e.what() << std::endl;
	}
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