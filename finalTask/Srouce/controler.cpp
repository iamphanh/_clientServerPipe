#include"../Header/controler.h"

#include<mutex>
#include <string>

controler::controler() {}
controler::~controler() {}

void controler::controlerS(server& _server)
{

	if (_server.getState()) {
		std::cout << "Server already existes!!" << std::endl;
		Sleep(1000);
		exit(1);
	}
	if (!_server.start())
	{
		std::cout << "Server start falied!!!" << std::endl;
		Sleep(1000);
		exit(1);
	}

};

void WINAPI controler::controlerC(client& _client)
{
	std::mutex clientS;
		if (_client.connect() == 0) {
			std::cout << "Connect successfull" << std::endl;
		}
		else if (_client.connect() == 1) {
			    clientS.lock();
				std::cout << "Create new server from client!!" << std::endl;
				server* _server = new server();
				controlerS(*_server);
				clientS.unlock();
		}
		else {
			std::cout << "Connect failed" << std::endl;
		}
}


