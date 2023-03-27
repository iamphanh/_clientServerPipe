#ifndef CONTROLER_H
#define CONTROLER_H

#include "../Header/server.h"
#include "../Header/client.h"
#include "../Header/display.h"

class Controler {
public:
	Controler();
	~Controler();

	static void WINAPI ControlerServer(Server& _server);
	static void WINAPI ControlerClient(Client& _client);

private:
	static Display display_;
};

#endif 