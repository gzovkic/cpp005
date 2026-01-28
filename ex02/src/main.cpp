#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    // Seed the randomizer for the Robotomy form
    std::srand(std::time(0));

    try 
	{
        Bureaucrat boss("The Boss", 1);
        Bureaucrat intern("The Intern", 150);

        std::cout << "--- Shrubbery Test ---" << std::endl;
        ShrubberyCreationForm shrub("home");
        
        // 1. Try to execute before signing
        boss.executeForm(shrub); 
        
        // 2. Sign and execute
        boss.signForm(shrub);
        boss.executeForm(shrub); // Should create home_shrubbery file

        std::cout << "\n--- Robotomy Test ---" << std::endl;
        RobotomyRequestForm robo("Bender");
        boss.signForm(robo);
        boss.executeForm(robo);
        boss.executeForm(robo); // Run twice to see the 50/50 chance

        std::cout << "\n--- Presidential Test ---" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        
        // 3. Intern tries to sign (too low grade)
        intern.signForm(pardon);
        
        // 4. Boss signs, but Intern tries to execute (too low grade)
        boss.signForm(pardon);
        intern.executeForm(pardon);
        
        // 5. Boss does everything
        boss.executeForm(pardon);

    }
	catch (std::exception &e)
	{
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}