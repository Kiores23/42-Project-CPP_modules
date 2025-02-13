#ifndef SHRUBBERYCREATIONFFORM_HPP
# define SHRUBBERYCREATIONFFORM_HPP

# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_Target;

		ShrubberyCreationForm();
	
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const & executor) const;
};

#endif