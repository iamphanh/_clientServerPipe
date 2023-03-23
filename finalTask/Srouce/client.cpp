#include "../Header/client.h"
#include "../Header/server.h"
#include "../Header/pipe.h"

BOOL WINAPI client::state = false;

client::client() {
	clientP = new pipe();
}
int __stdcall client::connect() const
{
    if (clientP->clientHandle()==0) {
		return 0;
		state = true;
		std::cout << "Client connect successfull!!!" << std::endl;
	}
	else if (clientP->clientHandle() == 233 || clientP->clientHandle() == 2)
	{
		return 1;
		state = false;
	}
	return false;
}
BOOL WINAPI client::getState() {
	return state;
};
client::~client() {
	delete clientP;
}