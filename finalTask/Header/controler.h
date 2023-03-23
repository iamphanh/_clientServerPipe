#ifndef CONTROLER_H
#define CONTROLER_H

#include "../Header/server.h"
#include "../Header/client.h"
#include "../Header/display.h"

class Controler {
public:
	Controler();
	~Controler();

	static void WINAPI ControlerS(Server& _server);
	static void WINAPI ControlerC(Client& _client);

private:
	static Display _display;
};

#endif 