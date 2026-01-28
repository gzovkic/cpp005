#pragma once 

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "default", 25, 5), _target("default")
{
	// std::cout 	<< BOLD << "PresidentialPardonForm deconstructor called"
	//				<< RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", target, 25, 5), _target(target)
{
	// std::cout 	<< BOLD << "PresidentialPardonForm deconstructor called"
	//				<< RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
	// std::cout 	<< BOLD << "PresidentialPardonForm deconstructor called"
	//				<< RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout 	<< BOLD << "PresidentialPardonForm deconstructor called"
	//				<< RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	this->checkRequierments(executor);

	std::cout	<< _target << " has been pardoned by Zaphod Beeblebrox."
				<< std::endl;
}