#include "../Header/display.h"

display::display() {}
display::~display() {}
char display::displayC1()
{
	/*client _client;
	_client.connect();*/
	std::cout << "\t\t\t>>>>>>> Client mode <<<<<<< " << std::endl;
	std::cout << "\t\tChoose mode: \n";
	std::cout << "\t\t '1' : Disconnect\n";
	std::cout << "\t\t '2' :Send and message\n";
	std::cout << "\t\t '4' : Back\n";
	std::cout << "\t\t '5' : Quit\n";
	std::cout << "Enter key: ";
	char c;
	std::cin >> c;
	return c;
}
char display::displayS1()
{
	/*server _server;*/
	std::cout << "\t\t\t>>>>>>> Server mode <<<<<<< " << std::endl;
	std::cout << "\t\tChoose mode: \n";
	std::cout << "\t\t '1' : Stop server\n";
	std::cout << "\t\t '2' : Start server\n";
	std::cout << "\t\t '4' : Back\n";
	std::cout << "\t\t '5' : Quit\n";
	std::cout << "Enter key: ";
	char c;
	std::cin >> c;
	return c;

}
char display::displayMenu()
{
	std::cout << "\n\n\n\n\t\t\t\t\t\tSERVER AND CLIENT\n\n\n\n";
	std::cout << "\t\tChoose mode: 1. Server\t\t\ 2.Client\t\t 3.Quit\n";
	std::cout << "\t\tEnter key: ";
	char c;
	std::cin >> c;
	return c;
}
