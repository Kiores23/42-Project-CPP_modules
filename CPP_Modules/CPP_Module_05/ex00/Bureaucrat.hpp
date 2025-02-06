#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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