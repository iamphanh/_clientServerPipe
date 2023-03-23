#define UNICODE
#define _UNICODE
#include "../Header/pipe.h"
#include "../Header/display.h"
#include <string>
#include <tchar.h>
pipe::pipe() {}
const LPCTSTR pipe::namePipe = TEXT("\\\\.\\pipe\\phanh");
HANDLE pipe::hpipe = INVALID_HANDLE_VALUE;
HANDLE pipe::fpipe = INVALID_HANDLE_VALUE;
BOOL pipe::serverHandle() {
	hpipe = CreateNamedPipe(namePipe,
		PIPE_ACCESS_DUPLEX, PIPE_TYPE_BYTE
		| PIPE_READMODE_BYTE | PIPE_WAIT,
		1, 1024, 1024, NMPWAIT_USE_DEFAULT_WAIT, NULL);
	if (hpipe == INVALID_HANDLE_VALUE) {
		std::cout << GetLastError();
		CloseHandle(hpipe);
		return false;
	}
	else
	{
		std::cout << "Create pipe successful!!" << std::endl;
		display _display;
		char c = _display.displayS1();
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
			DWORD dwWritten;
			std::cin.ignore();
			std::string str;
			std::cout << "Message: ";
			std::getline(std::cin, str);
			int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
			wchar_t* wstr = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
			LPCTSTR lpMsg = wstr;
			BOOL resultPipe;
			DWORD write;
			if (GetLastError() != ERROR_PIPE_CONNECTED) {
				resultPipe = WriteFile(hpipe,
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
				TCHAR  buf[1024];
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
			display::displayMenu();

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
int WINAPI pipe::clientHandle() {
	HANDLE fpipe;
	fpipe = CreateFile(namePipe,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_ARCHIVE,
		NULL);
	if (fpipe == INVALID_HANDLE_VALUE) {
		int erorr = WSAGetLastError();
		//std::cout << erorr;
		return erorr;
	}
	else {
		display _display;
		std::cout << "Client connect successfull!!!" << std::endl;
		char c = _display.displayC1();
		if (c == '1') {
			CloseHandle(fpipe);
		}
		else if (c == '2')
		{
			DWORD dwWritten;
			std::cin.ignore();
			std::string str;
			std::cout << "Message: ";
			std::getline(std::cin, str);
			int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
			wchar_t* wstr = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
			LPCTSTR lpMsg = wstr;
			BOOL resultPipe;
			DWORD write;
			resultPipe = WriteFile(fpipe,
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
			TCHAR  buf[1024];
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
			display::displayMenu();
		}
		else if (c == '5')
		{
			exit(1);

		}
		else
		{
			std::cout << "\n\t\tErorr:Invalid input characters" << std::endl;
			//continue;
		}
		return 0;
	}
}
pipe::~pipe() {}