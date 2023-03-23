
#ifndef SERVER_H
#define SERVER_H


#include "../Header/client.h"
#include"../Header/pipe.h"

class server {

private:
	static BOOL state;
	pipe* serverP;

public:
	server();
	~server();
	BOOL WINAPI start();
	static BOOL getState();
	static BOOL setState(BOOL x);
};
inline BOOL server::getState() {
	return state;
};

inline BOOL server::setState(BOOL x) {
	return state = x;
}
#endif // !SERVER_H