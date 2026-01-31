#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	// std::cout 	<< BOLD << "Intern Intern constructor called"
	// 			<< RESET << std::endl;
};


Intern::Intern(const Intern& other)
{
	*this = other;
	// std::cout << "Intern copy-constructed." << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	// std::cout << "Intern operator = assigned." << std::endl;
	if(this == &other)
		return(*this);
	return (*this);
}

Intern::~Intern()
{
	// std::cout 	<< BOLD << "Intern deconstructor called"
	// 			<< RESET << std::endl;
};

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};

    int i = 0;
    
    while(i < 3)
    {
        if(forms[i] == formName)
            break;
        i++;
    }
    switch(i)
    {
        case 0:
            std::cout 	<< BOLD << "Intern creates Robotomy request Form"
	        		    << RESET << std::endl;
            return (new RobotomyRequestForm(target));
        case 1:
        	std::cout 	<< BOLD << "Intern creates Shrubbery creation Form"
	        		    << RESET << std::endl;
            return (new ShrubberyCreationForm(target));
        case 2:
        	std::cout 	<< BOLD << "Intern creates Presidential pardon Form"
	        		    << RESET << std::endl;
            return (new PresidentialPardonForm(target));
        default:
        	std::cout 	<< BOLD << "Error: " << formName << " cannot be created(does not exist)"
	        		    << RESET << std::endl;
            return (NULL);
    }
}