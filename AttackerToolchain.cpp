#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <string>

// Função para encontrar o PID de um processo pelo nome
DWORD findProcessID(const std::wstring& processName) {
    PROCESSENTRY32W pe32 = { sizeof(PROCESSENTRY32W) };
    // O nome correto da função é com 'h' minúsculo
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    
    if (snapshot == INVALID_HANDLE_VALUE) return 0;

    if (Process32FirstW(snapshot, &pe32)) {
        do {
            if (processName == pe32.szExeFile) {
                CloseHandle(snapshot);
                return pe32.th32ProcessID;
            }
        } while (Process32NextW(snapshot, &pe32));
    }

    CloseHandle(snapshot);
    return 0;
}

int main() {
    // Exemplo de uso: procurando o bloco de notas
    DWORD pid = findProcessID(L"notepad.exe");

    if (pid != 0) {
        std::wcout << L"Processo encontrado! PID: " << pid << std::endl;
    } else {
        std::wcout << L"Processo nao encontrado." << std::endl;
    }

    return 0;
}
