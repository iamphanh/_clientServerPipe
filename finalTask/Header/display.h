#ifndef DISPLAY_H
#define DISPLAY_H

#include "server.h"
#include "client.h"

class server;

class Display {
public:
    Display();
    ~Display();
    static char DisplayMenu();
    static char DisplayS();
    static char DisplayC1();
};
#endif // DISPLAY_H
