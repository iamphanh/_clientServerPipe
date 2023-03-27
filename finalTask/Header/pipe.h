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
	static HANDLE hpipe_;
	static HANDLE fpipe_;
	static const LPCTSTR kname_pipe_;
};
#endif // PIPE_H

