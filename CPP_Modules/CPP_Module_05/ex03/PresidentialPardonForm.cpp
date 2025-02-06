#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "fstream"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 	AForm("PresidentialPardonForm", 25, 5), _Target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 25, 5), _Target(other._Target) {
	*this = other;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		_Target = other._Target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

AForm*	PresidentialPardonForm::clone(std::string target) {
	AForm*	clone = new PresidentialPardonForm(target);

	if (!clone)
		std::cout << "Error: new" << std::endl;
	return clone;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!isSigned()) {
		std::cout << executor.getName() << " couldn’t execute " << getName() << " because " << getName() << " is unsigned" << std::endl;
		return ;
	}
	if (executor.getGrade() <= getGradeRequiredToExecuteIt()) {
		std::cout << _Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	} else {
		throw GradeTooLowException();
	}
}