#ifndef CLIENT_H
#define CLIENT_H

#include "../Header/server.h"
#include"../Header/pipe.h"

class Client {
public:
	Client();
	~Client();

	int WINAPI ConnectServer() const;
	static BOOL WINAPI GetState();

private:
	Pipe* client_pipe_;
	static BOOL WINAPI state_;
};
#endif // CLIENT_H
