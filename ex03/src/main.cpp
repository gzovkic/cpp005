#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout 	<< YELLOW << "---- Robotomy ----"
	        	<< RESET << std::endl;
    {
    Intern someRandomIntern;
    Bureaucrat boss("Boss 1", 1);
    AForm* rrf;

    std::srand(std::time(0));
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    }
    std::cout 	<< YELLOW << "---- Shrubbery ----"
	        	<< RESET << std::endl;
    {
    Intern someRandomIntern;
    Bureaucrat boss("Boss 2", 1);
    AForm* rrf;

    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    }
    std::cout 	<< YELLOW << "---- Presidential ----"
	        	<< RESET << std::endl;
    {
    Intern someRandomIntern;
    Bureaucrat boss("Boss 3", 1);
    AForm* rrf;

    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }
    }
    std::cout 	<< YELLOW << "---- Fake ----"
	        	<< RESET << std::endl;
    {
    Intern someRandomIntern;
    Bureaucrat boss("Boss 4", 1);
    AForm* rrf;

    rrf = someRandomIntern.makeForm("fake", "Bender");
    
    if (rrf) {
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf; 
    }
    }
    
    return 0;
}