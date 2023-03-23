Write console application that can work in two modes: client and server.

Server broadcasts time for all clients.
Client write to console received data from server.
In each moment there must be only one server in the system.
If server dies, one of the clients must became server.

Requirements:
1. No third party library can be used.
2. c+11 features that supported in VS2010 can be used.
3. Win API can be used
4. It is up to which IPC to choose for communication between client and server but application design should support an ability to replace the selected IPC by another one
4. Application must work in Windows (XP, Vista, 7, 8)
5. OOP have to be used, but design should be as simple as possible to keep enough flexibility
6. Coding style have to be consistent

*****Detail:
+ Using IPC pipe in winAPI
+ User can choose to execute as server or client
+ The server listens for connections from the server, sends messages and receives messages from the client.
+ The client connects to the server to send messages, read messages from the incoming server.
+ No other clients have access while one client is reading or writing to the pipe.
