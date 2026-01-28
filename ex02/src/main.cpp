#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    std::srand(std::time(0));
    try 
	{
        Bureaucrat boss("The Boss", 1);
        Bureaucrat intern("The Intern", 150);

        std::cout << "--- Shrubbery Test ---" << std::endl;
        ShrubberyCreationForm shrub("home");
        
        boss.executeForm(shrub); 
        
        boss.signForm(shrub);
        boss.executeForm(shrub);

        std::cout << "\n--- Robotomy Test ---" << std::endl;
        RobotomyRequestForm robo("Bender");
        boss.signForm(robo);
        boss.executeForm(robo);
        boss.executeForm(robo);

        std::cout << "\n--- Presidential Test ---" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        
        intern.signForm(pardon);
        
        boss.signForm(pardon);
        intern.executeForm(pardon);
        
        boss.executeForm(pardon);

    }
	catch (std::exception &e)
	{
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}