#ifndef NETWORK_H
#define NETWORK_H

#include<iostream>
#include <stdio.h>

#include <ws2tcpip.h>
#include<Windows.h>
#include<winsock2.h>


class Network {
public:
	virtual ~Network() {};

	virtual BOOL ServerHandle() = 0;
	virtual int ClientHandle() = 0;

};

#endif // !NETWORK_H


