#include "../Header/server.h"

#include "../Header/client.h"
#include "../Header/pipe.h"

Server::Server() {
	server_p = new Pipe();
}

BOOL Server::state = false;

BOOL __stdcall Server::Start()
{
	if (!server_p->ServerHandle()) {
		std::cout << "Error creating named pipe\n";
		return false;
	}
	std::cout << "Client connected!\n";
	return true;
	
}

Server::~Server() {
	delete server_p;
}
