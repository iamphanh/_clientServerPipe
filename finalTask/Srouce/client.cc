#include "../Header/client.h"

#include "../Header/server.h"
#include "../Header/pipe.h"

BOOL WINAPI Client::state_ = false;

Client::Client() {
    client_pipe_ = new Pipe();
}
int __stdcall Client::ConnectServer() const
{
	if (client_pipe_->ClientHandle() == 0) {
		state_ = true;
		std::cout << "Client connect successfull!!!" << std::endl;
		return 0;
	} else if (client_pipe_->ClientHandle() == 233 ||
		client_pipe_->ClientHandle() == 2) {
		state_ = false;
		return 1;
	}
	return false;
}
BOOL WINAPI Client::GetState() {
	return state_;
}
Client::~Client() {
	delete client_pipe_;
}