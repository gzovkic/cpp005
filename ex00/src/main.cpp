#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("bob", 150);
	try
	{
		std::cout	<< BOLD << b1.getName() << RESET << ", has Grade " << GREEN << b1.getGrade() << RESET << " before Increment" 
					<< std::endl;
		b1.IncrementGrade();
		std::cout	<< BOLD << b1.getName() << RESET << ", has Grade " << GREEN << b1.getGrade() << RESET << " after Increment"
					<< std::endl;
		b1.DecrementGrade();
		std::cout	<< BOLD << b1.getName() << RESET << ", has Grade " << GREEN << b1.getGrade() << RESET << " after Decrement"
					<< std::endl;
		b1.DecrementGrade();
		std::cout	<< BOLD << b1.getName() << RESET << ", has Grade " << GREEN << b1.getGrade() << RESET << " after Decrement"
					<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr	<< RED << e.what() 
					<< RESET << std::endl;
	}
	return (0);
}