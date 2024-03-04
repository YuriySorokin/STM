#ifdef __MINGW32__
#include <windows.h>
#endif
#ifdef __linux
#include <sys/types.h>
#include <fcntl.h>
#endif
#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>


int main(){

    using namespace std;
     

     vector<string> msg{"hello","c++","world"};



    for (const string word : msg)
    {

        std::cout << word << ",";
    }
        std::cout << endl << " " ;

    printf ("test string");
    std:: cout << " test string " ;
    
HANDLE hSerial = CreateFile("COM3",GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
if (hSerial == INVALID_HANDLE_VALUE) {
printf("Error opening port\r\n");
return -1;
}

// запись в порт
    char * data ;
    data [0] = 0x01;
    DWORD dwBytesWrite = 0 ;
    if (!WriteFile(hSerial,data,1,&dwBytesWrite, NULL)){ printf("write error \r\n") ; }
// чтение из порта

    char * buffer ;
    if (!ReadFile(hSerial, buffer, 1,&dwBytesWrite,NULL)) {
        printf("read error");
    }
    else{
        printf ( "%s", buffer) ;
    }

// закрытие порта

CloseHandle(hSerial);


}
