#ifdef __MINGW32__
#include <windows.h>
#include <winnt.h>
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
     
/*
     vector<string> msg{"vecor 10 ","vector 30 ","vector 3"};



    for (const string word : msg)
    {

        std::cout << word << ",";
    }
        std::cout << endl << " " ;
*/
   // printf ("test string");
   // std:: cout << " test string " ;
    
    //typedef CHAR TCHAR;
    //typedef const TCHAR *LPCTSTR;

HANDLE hSerial ;
LPCTSTR sPortName = "COM3"; 

    printf ("Start open %s \n", sPortName );
       hSerial = CreateFile(sPortName,GENERIC_READ | GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
    if (hSerial == INVALID_HANDLE_VALUE) {
                                        printf("Error opening port 1 \r\n");
                                        return -1;
    }
    else {
    printf ("port opened \n");
    }

DCB dcbSerialParams = {0};
dcbSerialParams.DCBlength=sizeof(dcbSerialParams);
if (!GetCommState(hSerial, &dcbSerialParams))
{
        cout << "getting state error\n";
}

else { 
        cout << dcbSerialParams.BaudRate << '\n' ;
}
dcbSerialParams.BaudRate=CBR_9600;
dcbSerialParams.ByteSize=8;
dcbSerialParams.StopBits=ONESTOPBIT;
dcbSerialParams.Parity=NOPARITY;
if(!SetCommState(hSerial, &dcbSerialParams))
{
        cout << "error setting serial port state\n";
}

 

// запись в порт

    char data[7]  = "qwerty";

        DWORD dwBytesWrite = 0 ;

    //char buffer[2] ;


    printf ("write data \n") ;
    if (!WriteFile(hSerial,data,1,&dwBytesWrite, NULL)){ printf("write error \r\n") ; }
    else { printf ("write %s ok", sPortName );}


    printf ("read data \n") ;
    if (!ReadFile(hSerial, data, 16,&dwBytesWrite,NULL)) {
        printf("read error! \n");
    }
    else{
        printf ( " reading from port :  %s \n", data ) ;
    }
// чтение из порта



// закрытие порта
printf ("close port \n");
CloseHandle(hSerial);


}
