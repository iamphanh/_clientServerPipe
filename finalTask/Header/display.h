#ifndef DISPLAY_H
#define DISPLAY_H

#include "server.h"
#include "client.h"

class Server;

class Display {
public:
	Display();
	~Display();

	static char DisplayMenu();
	static char DisplayServer();
	static char DisplayClient();
};
#endif // DISPLAY_H
