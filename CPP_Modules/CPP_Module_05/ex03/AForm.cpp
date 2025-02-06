#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _GradeRequiredToSignIt(150), _GradeRequiredToExecuteIt(150){}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : 	_Name(name),
																	_GradeRequiredToSignIt(gradeToSign),
																	_GradeRequiredToExecuteIt(gradeToExec) {
	if (_GradeRequiredToSignIt < 1 || _GradeRequiredToExecuteIt < 1)
		throw GradeTooLowException();
	if (_GradeRequiredToSignIt > 150 || _GradeRequiredToExecuteIt > 150)
		throw GradeTooHighException();
	_IsSigned = false;
}

AForm::AForm(const AForm& other) :	_Name(other._Name),
								_GradeRequiredToSignIt(other._GradeRequiredToSignIt),
								_GradeRequiredToExecuteIt(other._GradeRequiredToExecuteIt){
	*this = other;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		_IsSigned = other._IsSigned;
	}
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const {
	return _Name;
}

bool		AForm::isSigned() const {
	return _IsSigned;
}

int	AForm::getGradeRequiredToSignIt() const {
	return _GradeRequiredToSignIt;
}

int	AForm::getGradeRequiredToExecuteIt() const {
	return _GradeRequiredToExecuteIt;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _GradeRequiredToSignIt ) {
		_IsSigned = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	std::string	sign;

	if (AForm.isSigned())
		sign = "Signed";
	else
		sign = "Unsigned";
	os << AForm.getName() << ", grade " << AForm.getGradeRequiredToSignIt() << " required for signature, " << AForm.getGradeRequiredToExecuteIt()
	<< " for execution. [" << sign << "]";
	return os;
}