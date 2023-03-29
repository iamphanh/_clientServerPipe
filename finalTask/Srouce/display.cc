#include "../Header/display.h"

Display::Display() {}
Display::~Display() {}
char Display::DisplayClient()
{
	std::cout << "\t\t\t>>>>>>> Client mode <<<<<<< " << std::endl;
	std::cout << "\t\tChoose mode: \n";
	std::cout << "\t\t '1' : Disconnect\n";
	std::cout << "\t\t '2' :Send and message\n";
	std::cout << "\t\t '5' : Quit\n";
	std::cout << "Enter key: ";
	char c;
	std::cin >> c;
	return c;
}
char Display::DisplayServer()
{
	std::cout << "\t\t\t>>>>>>> Server mode <<<<<<< " << std::endl;
	std::cout << "\t\tChoose mode: \n";
	std::cout << "\t\t '1' : Stop server\n";
	std::cout << "\t\t '2' : Start server\n";
	std::cout << "\t\t '5' : Quit\n";
	std::cout << "Enter key: ";
	char c;
	std::cin >> c;
	return c;

}
