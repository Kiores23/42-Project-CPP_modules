#include "Intern.hpp"

Intern::Intern() {
	_FormList[0] = new ShrubberyCreationForm("");
	_FormList[1] = new RobotomyRequestForm("");
	_FormList[2] = new PresidentialPardonForm("");
}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern&	Intern::operator=(const Intern& other) {
	if (this != &other) {
		;
	}
	return *this;
}

Intern::~Intern() {
	delete _FormList[0];
	delete _FormList[1];
	delete _FormList[2];
}

AForm	*Intern::makeForm(std::string name, std::string target) {
	int	i;

	for (i = 0; i < 3 && name != _FormList[i]->getName(); i++)
		;
	if (i < 3 && name == _FormList[i]->getName()) {
		AForm *form =_FormList[i]->clone(target);
		if (form)
			std::cout << "Intern creates " << name << std::endl;
		return form;
	}
	std::cout << "The intern did not understand what form he had to create." << std::endl;
	return NULL;
}