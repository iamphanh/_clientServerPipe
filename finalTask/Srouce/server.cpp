#include "../Header/server.h"
#include "../Header/client.h"
#include "../Header/pipe.h"

server::server() {
	serverP = new pipe();
}

BOOL server::state = false;

BOOL __stdcall server::start()
{
	if (!serverP->serverHandle()) {
		std::cout << "Error creating named pipe\n";
		return false;
	}
	std::cout << "Client connected!\n";
	return true;
	
}

server::~server() {
	delete serverP;
}
