#define UNICODE
#define _UNICODE
#define WIN32_LEAN_AND_MEAN
#pragma comment(lib, "ws2_32.lib")

#include "../Header/pipe.h"

#include "../Header/display.h"

#include <string>

#include <tchar.h>

Pipe::Pipe() {}
const LPCTSTR Pipe::kname_pipe = TEXT("\\\\.\\pipe\\phanh");
HANDLE Pipe::hpipe = INVALID_HANDLE_VALUE;
HANDLE Pipe::fpipe = INVALID_HANDLE_VALUE;
BOOL Pipe::ServerHandle() {
	hpipe = CreateNamedPipe(kname_pipe,
		PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE
		| PIPE_READMODE_BYTE | PIPE_WAIT,
		1, 1024, 1024, NMPWAIT_USE_DEFAULT_WAIT, NULL);
	if (hpipe == INVALID_HANDLE_VALUE) {
		std::cout << GetLastError();
		return false;
	}
	else
	{
		std::cout << "Create pipe successful!!" << std::endl;
		Display _display;
		char c = _display.DisplayS();
		if (c == '1') {
			DisconnectNamedPipe(hpipe);
			CloseHandle(hpipe);
		}
		else if (c == '2') {
			std::cout << "Waiting client connect ..." << std::endl;
			if (!ConnectNamedPipe(hpipe, NULL)) {
				std::cout << "Error connecting to client pipe. Error code: " << GetLastError() << std::endl;
				CloseHandle(hpipe);
				return false;
			}
			DWORD dwWritten, write;
			TCHAR  buf[1024];
			std::cin.ignore();
			std::string str;
			std::cout << "Message: ";
			std::getline(std::cin, str);
			int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
			wchar_t* wstr = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
			LPCTSTR lpMsg = wstr;
			if (GetLastError() != ERROR_PIPE_CONNECTED) {
				BOOL resultPipe = WriteFile(hpipe,
					lpMsg,
					DWORD((lstrlen(lpMsg) + 1) * sizeof(TCHAR)),
					&write,
					NULL);
				if (resultPipe == false) {
					std::cout << "Error: WriteFile failed with error " << GetLastError() << std::endl;
					CloseHandle(hpipe);
					return false;
				}
				std::cout << "Send message successful!!" << std::endl;
				std::cout << "Waiting read from client ..." << std::endl;
				if (!ReadFile(hpipe, buf, 1024 * sizeof(TCHAR), &dwWritten, NULL))
				{
					printf("Error reading from pipe. Error code: %d\n", GetLastError());
					CloseHandle(hpipe);
					return false;
				}
				std::cout << "Received response from client: ";
				_tprintf(TEXT("\"%s\"\n"), buf);
			}
			else {
				std::cout << "Error connecting to client pipe. Error code: " << GetLastError() << std::endl;
				CloseHandle(hpipe);
				return false;
			}
			CloseHandle(hpipe);
			return true;
		}
		else if (c == '4') {
			Display::DisplayMenu();

		}
		else if (c == '5') {
			exit(1);
		}
		else
		{
			std::cout << "\n\t\tErorr:Invalid input characters" << std::endl;
		}
		return true;
	}
};
int WINAPI Pipe::ClientHandle() {
	HANDLE fpipe = CreateFile(kname_pipe,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_ARCHIVE,
		NULL);
	if (fpipe == INVALID_HANDLE_VALUE) {
		int erorr = WSAGetLastError();
		return erorr;
	}
	else {
		Display _display;
		std::cout << "Client connect successfull!!!" << std::endl;
		char c = _display.DisplayC1();
		if (c == '1') {
			CloseHandle(fpipe);
		}
		else if (c == '2')
		{
			DWORD dwWritten, write;
			TCHAR  buf[1024];
			std::cin.ignore();
			std::string str;
			std::cout << "Message: ";
			std::getline(std::cin, str);
			int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
			wchar_t* wstr = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
			LPCTSTR lpMsg = wstr;
			BOOL resultPipe = WriteFile(fpipe,
				lpMsg,
				DWORD((lstrlen(lpMsg) + 1) * sizeof(TCHAR)),
				&write,
				NULL);
			std::cout << "Send message successful!!" << std::endl;
			if (!resultPipe) {
				std::cout << "Error: WriteFile failed with error " << GetLastError() << std::endl;
				CloseHandle(fpipe);
				return 1;
			}
			std::cout << "Waiting read from server ..." << std::endl;
			if (!ReadFile(fpipe, buf, 1024 * sizeof(TCHAR), &dwWritten, NULL))
			{
				printf("Error reading from pipe. Error code: %d\n", GetLastError());
				CloseHandle(fpipe);
				return 1;
			}
			std::cout << "Received response from server: ";
			_tprintf(TEXT("\"%s\"\n"), buf);
			CloseHandle(fpipe);
			return 0;

		}
		else if (c == '4') {
			Display::DisplayMenu();
		}
		else if (c == '5')
		{
			exit(1);

		}
		else
		{
			std::cout << "\n\t\tErorr:Invalid input characters" << std::endl;
		}
		return 0;
	}
}
Pipe::~Pipe() {}