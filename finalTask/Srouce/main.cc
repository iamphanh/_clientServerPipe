#include "../Header/client.h"
#include "../Header/server.h"
#include "../Header/controler.h"

#include <thread>
#include <mutex>

int main() {
	std::mutex mutex_server;
	do {
		char c = Display::DisplayMenu();
		if (c == '1') {
			mutex_server.lock();
			Server* _server = new Server();
			Controler::ControlerServer(*_server);
			mutex_server.unlock();

		} else if (c == '2') {
			Client* _client = new Client();
			Controler::ControlerClient(*_client);

		} else if (c == '3') {
			exit(1);
		} else {
			std::cout << "Input character invailed!!" << std::endl;
			break;
		}
	} while (true);
}