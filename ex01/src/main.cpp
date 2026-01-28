#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 40);
		Form taxForm("Tax Form", 45, 45);

		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);
	} catch (std::exception &e) {
		std::cerr << "Main catch: " << e.what() << std::endl;
	}
	return (0);
}