#ifndef PIPE_H
#define PIPE_H
#include <conio.h>
#include "../Header/network.h"

class pipe : public network {
private:
    static HANDLE hpipe;
    static HANDLE fpipe;
    static const LPCTSTR namePipe;
public:
    pipe();
    ~pipe();
    BOOL serverHandle() override;
    int clientHandle() override;
};
#endif // PIPE_H

