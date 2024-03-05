#ifdef __MINGW32__
#include <windows.h>
#endif
#ifdef __linux
#include <sys/types.h>
#include <fcntl.h>
#endif
#include <stdio.h>



int main(){

    printf ("test string");
    // std:: cout << " test string " ;

}