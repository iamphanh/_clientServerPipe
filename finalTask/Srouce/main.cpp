#include "../Header/client.h"
#include "../Header/server.h"
#include "../Header/controler.h"
#include <thread>
#include <mutex>

int main() {
	std::mutex mutexS;
	do {
		char c = display::displayMenu();
		if (c == '1') {
			mutexS.lock();
			server* _server = new server();
			controler::controlerS(*_server);
			mutexS.unlock();

		}
		else if (c == '2') {
			client* _client = new client();
			controler::controlerC(*_client);

		}
		else if (c == '3') {
			exit(1);
		}
		else {
			std::cout << "Input character invailed!!" << std::endl;
			break;
		}
	} while (true);

}