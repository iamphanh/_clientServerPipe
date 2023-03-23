#ifndef CLIENT_H
#define CLIENT_H

#include "../Header/server.h"
#include"../Header/pipe.h"


class client {
private:
	pipe* clientP;
	static BOOL WINAPI state;
public:
	client();
	~client();
	int WINAPI connect() const;
	static BOOL WINAPI getState();
	
};

#endif // CLIENT_H
