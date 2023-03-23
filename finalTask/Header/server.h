#ifndef SERVER_H
#define SERVER_H
#include "../Header/client.h"

#include"../Header/pipe.h"

class Server {
public:
	Server();
	~Server();

	BOOL WINAPI Start();
	static BOOL GetState();
	static BOOL SetState(BOOL x);

private:
	static BOOL state;
	Pipe* server_p;
};

inline BOOL Server::GetState() {
	return state;
}
inline BOOL Server::SetState(BOOL x) {
	return state = x;
}
#endif // !SERVER_H