#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 	AForm("ShrubberyCreationForm", 145, 137), _Target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), _Target(other._Target) {
	*this = other;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		_Target = other._Target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!isSigned()) {
		std::cout << executor.getName() << " couldn’t execute " << getName() << " because " << getName() << " is unsigned" << std::endl;
		return ;
	}
	if (executor.getGrade() <= getGradeRequiredToExecuteIt()) {
		std::string		folderName = _Target + "_shrubbery";
		std::ofstream	newFolder(folderName.c_str());
		if (newFolder.is_open()) {
			newFolder	<< "       _-_" << std::endl \
						<< "    /~~   ~~\\" << std::endl \
						<< " /~~         ~~\\" << std::endl \
						<< "{               }" << std::endl \
						<< " \\  _-     -_  /" << std::endl \
						<< "   ~  \\\\ //  ~" << std::endl \
						<< "_- -   | | _- _" << std::endl \
						<< "  _ -  | |   -_" << std::endl \
						<< "      // \\\\" << std::endl;
			newFolder.close();
		} else {
			std::cout << folderName << " could not be created" << std::endl;
		}
	} else {
		throw GradeTooLowException();
	}
}