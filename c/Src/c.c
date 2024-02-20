#include <stdio.h>
#include "stdbool.h"
#include <string.h>

//#define noerror 0 ;

#define L_BUFFER_STRING 512

enum errorNum {
	noerror = 0,
	File_open_error = 1
} ;

int errornum = 0 ;

enum progress {
	exceeded_L_BUFFER_STRING = 1,
	reached_EOL = 2,
	reached_EOF = 3

}

void press_AnyKey(void); // press any key only

int getc_from_file();  

int file_open ( FILE** , char*); // открытие файла с коммандной строки 1 арг

int file_printf ( FILE* , char* );

int get_one_line( FILE * , char * ) ;
int get_first_line( FILE * , char * ) ;

int file_open ( FILE* *file , char argv[] ){

	char str[512] = {'0'};

	if ((*file = fopen(argv, "r")) == NULL){
							       printf("Не удалось открыть файл");
											   	return File_open_error;
	}

	return noerror ;
	// проверка открытия файла, выборка строк, если нужна проверка
		while (
				fgets(str, 512, *file) != NULL 
		)

		{
				 printf("%s\n", str ) ;
		}
	// закрытие файла		
    	fclose(*file);

								     printf (" \nFile closed \n");

		return noerror ;
}

int file_printf ( FILE *file , char argv[] ){

	char str[512] = {'0'};

	if ((file = fopen(argv, "r")) == NULL){
							       printf("Не удалось открыть файл");
										       getchar();
			
								   		     	return 1;
	}
	
	      // открыть файл удалось
	      // требуемые действия над данными

	printf("файл открыт \n");	
		
		printf("вывод строк из файла \n" ) ;
		while (
				fgets(str, 512, file) != NULL 
		)

		{
				 printf("%s\n", str ) ;
		}

    		getchar();
											return 0 ;
}


int get_first_line( FILE *fp , char *in_string ) {
	char symbol = '0';
	char str[L_BUFFER_STRING] = {'0'} ;
	int i = 0 ;

  	  while 	(	(( symbol = fgetc(fp)) != EOF) 
						&&
					( symbol != 0x0A)		// конец строки
						&&
					( i < L_BUFFER_STRING )
				)
			{
				
				/*
				str[1] = '\50'; 			// работает (
				str[2] = (int) symbol ; 	// работает m
				str[3] = symbol ; 			// работает e
				*/

				in_string[i] = symbol ;			// работает
				// printf (" %c  ", symbol ) ; 	// работает 
				
				//printf ("  i = %d , str[%d] = %c  \n", i,i, in_string[i]);
/*
				if (str[i] == ',') {
							str[i] = '\0';
							printf("%s\n", str);
			    				i = 0;
		    				    }
				    else { i++; } */
				i++ ;
			}

			// in_string = str ;
			//printf ("\n instring = %s  ", in_string );

		}

int get_one_line( FILE *fp , char *in_string ) {
	char symbol = '0';
	char str[L_BUFFER_STRING] = {'0'} ;
	int i = 0 ;
	int res = 0, res1 = 0, res2 = 0, res3 = 0 ; 
	enum progress STATUS ;

  	  while 	(	(( symbol = fgetc(fp)) != EOF) 
						&&
					( symbol != 0x0A)
						&&
					( i < L_BUFFER_STRING )
				)
			{
				in_string[i] = symbol ;			// работает
				i++ ;
			}

	res1 = i >= L_BUFFER_STRING ;
	res2 = symbol == 0x0A ;
	res3 = symbol == EOF ;
	res = res1 + res2*10 +res3*100 ;
		
		switch ( res )
		{
			case res1 : { STATUS = exceeded_L_BUFFER_STRING ;
						}; break ;
			case res2 : { STATUS = reached_EOL ; 
						}; break ;
			case res3 : { STATUS = reached_EOF ;
						}; break ;

			default :  break ;

		}
}

int main (int argc, char *argv[]){


	FILE *fp;
	int i = 0 ;	

	char str[512] = {'\0'};
	char symbol = '\0';
	  
	if ( file_open( &fp, argv[1] ) == noerror );
{
		get_first_line( fp , str );
}
	printf (" \n 1-st string from file is : \n %s ", str );
	printf ("\n");
	
		get_one_line( fp, str ) ;

	printf (" \n next string from file is : \n %s ", str );
	printf ("\n");
	

return noerror ;

  	  while 	(	(( symbol = fgetc(fp)) != EOF) 
						&&
					( i < 512 )
				)
			{
				
				/*
				str[1] = '\50'; // работает (
				str[2] = (int) symbol ; // работает m
				str[3] = symbol ; // работает e
				*/

				str[i] = symbol ;			// работает
				printf (" %c  ", symbol ) ; // работает 
				
				printf ("  i = %d , str[%d] = %c  \n", i,i, str[i]);
				/*
				if (str[i] == ',') {
							str[i] = '\0';
							printf("%s\n", str);
			    				i = 0;
		    				    }
				    else { i++; } */
					i++ ;
			}	

	    str[i] = '\0';
	    printf("%s\n",str);
	    printf("i=%d\n",i);

    	    fclose(fp);
	    press_AnyKey();

//		getc_from_file(); 

	 return noerror ;
}

/*
bool csv_parse_text(const char* const text,
                    char separator, 
                    uint32_t index, 
                    char* const sub_str,
                    uint32_t sub_str_size 
		    ) 
		    { 

}
*/

#define N 80
 
int getc_from_file(void) { 
	    FILE *file;
	    char str[N];
	    int i;
	
	    file = fopen("goods.txt", "r");

	    while ((str[i] = fgetc(file)) != EOF) {

		    if (str[i] == '\n') {

			    str[i] = '\0';

			    printf("%s\n", str);

			    i = 0;

		    }

		    else i++;
	    }

	    str[i] = '\0';

	    printf("%s\n",str);

	    fclose(file);

}


void press_AnyKey(void) { // 
												printf("press anykey");
		getchar();
}
