#include "Form.hpp"

Form::Form()
	: _name("default"), _gradeSign(150), _gradeExe(150), _signed(false)
{
	// std::cout 	<< BOLD << "Form Form constructor called"
	// 			<< RESET << std::endl;
};


Form::Form(const Form& other)
	: _name(other._name), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe), _signed(other._signed)
{
	if (this->_gradeSign < 1 || this->_gradeExe < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExe > 150)
		throw Form::GradeTooLowException();
	// std::cout << "Form copy-constructed." << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExe)
: _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe), _signed(false)
{
	if (this->_gradeSign < 1 || this->_gradeExe < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExe > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	// std::cout << "Form operator = assigned." << std::endl;
	if(this == &other)
		return(*this);
	this->_signed = other._signed;
	return (*this);
}

Form::~Form()
{
	// std::cout 	<< BOLD << "Form deconstructor called"
	// 			<< RESET << std::endl;
};

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int Form::getGradeExe() const
{
	return (this->_gradeExe);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade is to high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade is to low!");
}


std::ostream& operator<<(std::ostream& o, const Form& rhs)
{
	o 	<< rhs.getName() << ":\n"
		<< "_gradeSign " << rhs.getGradeSign() << "'\n"
		<< "_gradeExe " << rhs.getGradeExe() << "'\n"
		<< "_signed" << rhs.getSigned() << "'\n";
	return(o);
}

void Form::beSigned(const Bureaucrat& bure)
{
	if(bure.getGrade() <= this->_gradeSign)
	{
		this->_signed = true;
		return ;
	}
	throw GradeTooLowException();
}
