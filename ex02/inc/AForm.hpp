#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	public:
		AForm();
		~AForm();
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);

		AForm(std::string type, std::string name, int gradeSign, int gradeExe);
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExe() const;
		bool getSigned() const;
		std::string getType() const;
		void beSigned(const Bureaucrat& bure);

		void	checkRequierments(Bureaucrat const& bure) const;
		virtual void execute(Bureaucrat const& execute) const = 0;
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

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw(); 
		};

	private:
		const std::string _type;
		const std::string _name;
		const int _gradeSign;
		const int _gradeExe; 
		bool _signed;
};

std::ostream& operator<<(std::ostream& o, const AForm& rhs);