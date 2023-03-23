#include "../Header/client.h"

#include "../Header/server.h"
#include "../Header/pipe.h"

BOOL WINAPI Client::state = false;

Client::Client() {
	client_p= new Pipe();
}
int __stdcall Client::ConnectC() const
{
    if (client_p->ClientHandle()==0) {
		state = true;
		std::cout << "Client connect successfull!!!" << std::endl;
		return 0;
	}
	else if (client_p->ClientHandle() == 233 || client_p->ClientHandle() == 2)
	{
		state = false;
		return 1;
	}
	return false;
}
BOOL WINAPI Client::GetState() {
	return state;
};
Client::~Client() {
	delete client_p;
}