#ifndef PIPE_H
#define PIPE_H
//#include <conio.h>
#include "../Header/network.h"

class Pipe : public Network {
private:
    static HANDLE hpipe;
    static HANDLE fpipe;
    static const LPCTSTR kname_pipe;
public:
    Pipe();
    ~Pipe();
    BOOL ServerHandle() override;
    int ClientHandle() override;
};
#endif // PIPE_H

