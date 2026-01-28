#pragma once

#include "Bureaucrat.hpp"

class Form
{
	public:
		Form();
		~Form();
		Form(const Form& other);
		Form& operator=(const Form& other);

		Form(std::string name, int gradeSign, int gradeExe);
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExe() const;
		bool getSigned() const;
		
		void beSigned(const Bureaucrat& bure);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};

	private:
		const std::string _name;
		const int _gradeSign;
		const int _gradeExe; 
		bool _signed;
};

std::ostream& operator<<(std::ostream& o, const Form& rhs);