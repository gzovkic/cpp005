#include "AForm.hpp"

AForm::AForm()
	: _type("default"), _name("default"), _gradeSign(150), _gradeExe(150), _signed(false)
{
	// std::cout 	<< BOLD << "AForm AForm constructor called"
	// 			<< RESET << std::endl;
};


AForm::AForm(const AForm& other)
	: _type(other._type), _name(other._name), _gradeSign(other._gradeSign), _gradeExe(other._gradeExe), _signed(other._signed)
{
	if (this->_gradeSign < 1 || this->_gradeExe < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExe > 150)
		throw AForm::GradeTooLowException();
	// std::cout << "AForm copy-constructed." << std::endl;
}

AForm::AForm(std::string type, std::string name, int gradeSign, int gradeExe)
: _type(type), _name(name), _gradeSign(gradeSign), _gradeExe(gradeExe), _signed(false)
{
	if (this->_gradeSign < 1 || this->_gradeExe < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeSign > 150 || this->_gradeExe > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	// std::cout << "AForm operator = assigned." << std::endl;
	if(this == &other)
		return(*this);
	this->_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
	// std::cout 	<< BOLD << "AForm deconstructor called"
	// 			<< RESET << std::endl;
};

std::string AForm::getType() const
{
	return (this->_type);
}


std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int AForm::getGradeExe() const
{
	return (this->_gradeExe);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade is to high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade is to low!");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return("Form is not signed!");
}

std::ostream& operator<<(std::ostream& o, const AForm& rhs)
{
	o 	<< rhs.getName() << ":\n"
		<< "_gradeSign " << rhs.getGradeSign() << "'\n"
		<< "_gradeExe " << rhs.getGradeExe() << "'\n"
		<< "_signed" << rhs.getSigned() << "'\n";
	return(o);
}

void AForm::beSigned(const Bureaucrat& bure)
{
	if(bure.getGrade() <= this->_gradeSign)
	{
		this->_signed = true;
		return ;
	}
	throw GradeTooLowException();
}

void AForm::checkRequierments(Bureaucrat const& bure) const
{
	if(this->getSigned() == false)
		throw FormNotSigned();
	else if(bure.getGrade() > this->getGradeExe())
		throw GradeTooLowException();
}