#pragma once 

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "default", 72, 45), _target("default")
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", target, 72, 45), _target(target)
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	this->checkRequierments(executor);
	std::cout	<< "* drilling noises *"
				<< std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
}