#define UNICODE
#define _UNICODE
#include"../Header/controler.h"

#include<mutex>
#include <string>

Controler::Controler() {}
Controler::~Controler() {}
void Controler::ControlerS(Server& _server)
{
	if (_server.GetState()) {
		std::cout << "Server already existes!!" << std::endl;
		Sleep(1000);
		exit(1);
	}
	if (!_server.Start()) {
		std::cout << "Server start falied!!!" << std::endl;
		Sleep(1000);
		exit(1);
	}
}
void WINAPI Controler::ControlerC(Client& _client)
{
	std::mutex clientS;
	if (_client.ConnectC() == 0) {
		std::cout << "Connect successfull" << std::endl;
	} else if (_client.ConnectC() == 1) {
		clientS.lock();
		std::cout << "Create new server from client!!" << std::endl;
		Server* _server = new Server();
		ControlerS(*_server);
		clientS.unlock();
	} else {
		std::cout << "Connect failed" << std::endl;
	}
}


