
#include "stdio.h"


void main (void) {

    


    int x;
    int y ;
    
    x = 500 ;

    y = *((short *)(&x));

    printf(" x = %d", x );
    printf(" y = %d", y );
    
    

}