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
	static BOOL state_;
	Pipe* server_pipe_;
};

inline BOOL Server::GetState() {
	return state_;
}
inline BOOL Server::SetState(BOOL x) {
	return state_ = x;
}
#endif // !SERVER_H