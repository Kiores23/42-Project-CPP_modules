#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_Name;
		bool				_IsSigned;
		const int			_GradeRequiredToSignIt;
		const int			_GradeRequiredToExecuteIt;

		AForm();
	
	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm& other);
		AForm&	operator=(const AForm& other);
		virtual ~AForm();

		std::string		getName() const;
		bool			isSigned() const;
		int				getGradeRequiredToSignIt() const;
		int				getGradeRequiredToExecuteIt() const;
		void			beSigned(const Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
    		public:
        		virtual const char* what() const throw();
   		};
	
		class GradeTooLowException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};
};

std::ostream& operator<<(std::ostream& os, const AForm& Form);

#endif