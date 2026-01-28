#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
	// std::cout 	<< BOLD << "Bureaucrat Bureaucrat constructor called"
	// 			<< RESET << std::endl;
};


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	// std::cout << "Bureaucrat copy-constructed." << std::endl;
	this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	// std::cout << "Bureaucrat operator = assigned." << std::endl;
	if(this == &other)
		return(*this);
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout 	<< BOLD << "Bureaucrat deconstructor called"
	// 			<< RESET << std::endl;
};

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

Bureaucrat::Bureaucrat(std::string name, int i)
	:_name(name)
{
	if(i < 1)
		throw (GradeTooHighException());
	else if (i > 150)
		throw (GradeTooLowException());
	
	this->_grade = i;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade is to high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade is to low!");
}

void Bureaucrat::IncrementGrade()
{
	if(this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::DecrementGrade()
{
	if(this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o 	<< rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "'";
	return(o);
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this); 
		std::cout	<< f.getName() << " signed " << this->_name
					<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr	<< f.getName() << " couldn't sign " << this->_name
					<< " because " << e.what()
					<< std::endl;
	}
}