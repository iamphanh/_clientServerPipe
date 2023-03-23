#ifndef PIPE_H
#define PIPE_H

#include "../Header/network.h"

class Pipe : public Network {
public:
	Pipe();
	~Pipe();

	BOOL ServerHandle() override;
	int ClientHandle() override;

private:
	static HANDLE hpipe;
	static HANDLE fpipe;
	static const LPCTSTR kname_pipe;
};
#endif // PIPE_H

