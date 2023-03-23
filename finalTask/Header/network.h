#ifndef NETWORK_H
#define NETWORK_H
#define WIN32_LEAN_AND_MEAN
#pragma comment(lib, "ws2_32.lib")
#include <ws2tcpip.h>
#include<Windows.h>
#include<winsock2.h>
#include<iostream>
#include <stdio.h>

class network {
public:
    virtual ~network() {};
    virtual BOOL serverHandle() = 0;
    virtual int clientHandle() = 0;

};

#endif // !NETWORK_H


