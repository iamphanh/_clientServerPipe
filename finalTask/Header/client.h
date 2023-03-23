#ifndef CLIENT_H
#define CLIENT_H

#include "../Header/server.h"
#include"../Header/pipe.h"


class Client {
private:
	Pipe* client_p;
	static BOOL WINAPI state;
public:
	Client();
	~Client();
	int WINAPI ConnectC() const;
	static BOOL WINAPI GetState();
	
};

#endif // CLIENT_H
