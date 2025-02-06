#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 	AForm("RobotomyRequestForm", 72, 45), _Target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), _Target(other._Target) {
	*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		_Target = other._Target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!isSigned()) {
		std::cout << executor.getName() << " couldn’t execute " << getName() << " because " << getName() << " is unsigned" << std::endl;
		return ;
	}
	if (executor.getGrade() <= getGradeRequiredToExecuteIt()) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		
		int randomValue = std::rand() % 2;
		bool robotomized =	static_cast<bool>(randomValue);
		
		if (robotomized)
    	    std::cout << "*Some drilling noises*" << std::endl << "La robotomisation a réussi." << std::endl;
    	else
        	std::cout << "*Some drilling noises*" << std::endl << "La robotomisation a échoué." << std::endl;
	} else {
		throw GradeTooLowException();
	}
}