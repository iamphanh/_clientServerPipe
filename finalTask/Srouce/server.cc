#include "../Header/server.h"

#include "../Header/client.h"
#include "../Header/pipe.h"

Server::Server() {
	server_pipe_ = new Pipe();
}
BOOL Server::state_ = false;
BOOL __stdcall Server::Start()
{
	if (!server_pipe_->ServerHandle()) {
		std::cout << "Error creating named pipe\n";
		return false;
	}
	std::cout << "Client connected!\n";
	return true;
}
Server::~Server() {
	delete server_pipe_;
}
