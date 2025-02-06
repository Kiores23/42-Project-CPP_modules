#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Bureaucrat
{
	private:
		const std::string	_Name;
		int					_Grade;
	
		Bureaucrat();
	
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void		promotion();
		void		demotion();
		void		signForm(AForm& form);
		void		executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
    		public:
        		virtual const char* what() const throw();
   		};
	
		class GradeTooLowException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif