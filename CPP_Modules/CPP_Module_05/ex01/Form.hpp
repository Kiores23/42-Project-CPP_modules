#ifndef Form_HPP
# define Form_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_Name;
		bool				_IsSigned;
		const int			_GradeRequiredToSignIt;
		const int			_GradeRequiredToExecuteIt;

		Form();
	
	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form();

		std::string	getName() const;
		bool		isSigned() const;
		int			getGradeRequiredToSignIt() const;
		int			getGradeRequiredToExecuteIt() const;
		void		beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception {
    		public:
        		virtual const char* what() const throw();
   		};
	
		class GradeTooLowException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif