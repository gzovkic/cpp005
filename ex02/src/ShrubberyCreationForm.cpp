#pragma once 

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "default", 145, 137), _target("default")
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", target, 145, 137), _target(target)
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	// std::cout 	<< BOLD << "Shrubbery deconstructor called"
	//				<< RESET << std::endl;
}