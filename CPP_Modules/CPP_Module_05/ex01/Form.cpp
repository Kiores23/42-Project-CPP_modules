#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _GradeRequiredToSignIt(150), _GradeRequiredToExecuteIt(150){}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : 	_Name(name),
																	_GradeRequiredToSignIt(gradeToSign),
																	_GradeRequiredToExecuteIt(gradeToExec) {
	if (_GradeRequiredToSignIt < 1 || _GradeRequiredToExecuteIt < 1)
		throw GradeTooLowException();
	if (_GradeRequiredToSignIt > 150 || _GradeRequiredToExecuteIt > 150)
		throw GradeTooHighException();
	_IsSigned = false;
}

Form::Form(const Form& other) :	_Name(other._Name),
								_GradeRequiredToSignIt(other._GradeRequiredToSignIt),
								_GradeRequiredToExecuteIt(other._GradeRequiredToExecuteIt){
	*this = other;
}

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		_IsSigned = other._IsSigned;
	}
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const {
	return _Name;
}

bool		Form::isSigned() const {
	return _IsSigned;
}

int	Form::getGradeRequiredToSignIt() const {
	return _GradeRequiredToSignIt;
}

int	Form::getGradeRequiredToExecuteIt() const {
	return _GradeRequiredToExecuteIt;
}


const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _GradeRequiredToSignIt ) {
		_IsSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	std::string	sign;

	if (form.isSigned())
		sign = "Signed";
	else
		sign = "Unsigned";
	os << form.getName() << ", grade " << form.getGradeRequiredToSignIt() << " required for signature, " << form.getGradeRequiredToExecuteIt()
	<< " for execution. [" << sign << "]";
	return os;
}