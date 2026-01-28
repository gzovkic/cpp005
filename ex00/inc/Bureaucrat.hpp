#pragma once

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>


class Bureaucrat
{
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName() const;
		int getGrade() const;

		Bureaucrat(std::string name, int i);
		void IncrementGrade();
		void DecrementGrade();
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
		int _grade; 
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);