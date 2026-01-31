#include "Intern.hpp"
#include "AForm.hpp"


Intern::Intern()
{
	// std::cout 	<< BOLD << "Intern Intern constructor called"
	// 			<< RESET << std::endl;
};


Intern::Intern(const Intern& other)
{
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
    
}