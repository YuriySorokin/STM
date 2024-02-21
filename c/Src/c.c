#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#define noerror 0 ;

#define L_BUFFER_STRING 512
#define EOL 0x0A 

enum errorNum {
	noerror = 0,
	File_open_error = 1
} ;

int errornum = 0 ;


enum progress {
	OK = 0 ,
	exceeded_L_BUFFER_STRING = 1,
	reached_EOL = 2,
	reached_EOF = 3,
	FAULT = 10
} ;

struct point {
	int index ;
	float time ;
	float ch1_V ;
	// float time_increment ;
} ;


void press_AnyKey(void); // press any key only



int getc_from_file();  

int file_open ( FILE** , char*); // открытие файла с коммандной строки 1 арг

int file_printf ( FILE* , char* );

int get_first_line( FILE * , char * ) ;
int get_next_line( FILE * , char * ) ;
int csv_parse_string( char *, struct point *  ) ;
int get_col ( char *, char, float *, float * );




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
	// char str[L_BUFFER_STRING] = {'0'} ;
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

int get_next_line( FILE *fp , char *in_string ) {
	char symbol = '0';
	char str[L_BUFFER_STRING] = {'0'} ;
	int i = 0 ;
	int res = 0, res1 = 0, res2 = 0, res3 = 0 ; 
	enum progress STATUS = OK ;

  	  while 	(	(( symbol = fgetc(fp)) != EOF) 
						&&
					( symbol != EOL )
						&&
					( i < L_BUFFER_STRING )
				)
			{
				in_string[i] = symbol ;			// работает
				i++ ;
			}
				in_string[i] = '\0' ;			// завершить строку 

	res1 = symbol == EOL ; // 
	res2 = symbol == EOF ;
	res3 = i >= L_BUFFER_STRING ;

	res = res1 + res2*10 +res3*100 ;
		
		switch ( res )
		{
			case 1 : { STATUS = reached_EOL ;
						} ; break ;
			case 10 : { STATUS = reached_EOF ; 
						} ; break ;
			case 100 : { STATUS = L_BUFFER_STRING ;
						} ; break ;
			default : { STATUS = FAULT ;
				// 111,11,101,110

			} break ;
		}

		return STATUS ; 
}

int main (int argc, char *argv[]){


	FILE *fp;
	int i = 0 ;	

	char str[L_BUFFER_STRING] = {'\0'};
	char symbol = '\0';
	  
	if ( file_open( &fp, argv[1] ) == noerror );
{
		get_first_line( fp , str );
}
	printf (" \n 1-st string from file is : \n %s ", str );
	printf ("\n");
	
		get_next_line( fp, str ) ;

	printf (" \n next string from file is : \n %s ", str );
	printf ("\n");

	char separator = ',' ;
	struct point _Point ;
	//float value32 = 7.1635E-06;

		//_Point.time = value32 ;
		//_Point.ch1_V = -1.014158e+01 ;

		csv_parse_string( str, &_Point  ) ;	

	printf ("\n Вывод из main \n") ;
	printf(" \n string :   %s \n", str );

	printf(" \n *time :   %e \n", _Point.time );

	printf(" \n *ch1_V :   %e \n", _Point.ch1_V );





return noerror ;


    	    fclose(fp);
	    press_AnyKey();

	 return noerror ;
}







int csv_parse_string( char *in_string, struct point *_Point  ) {
 // csv_parse_text( char* in_string, char separator, struct point *Point  ) {
		char separator = ',';
		// printf (" Вывод из csv_parse_text : \n") ;	//OK
		// printf ("!!! Separator : %c \n", separator) ; //OK
		get_col ( in_string,  separator, &_Point->time, &_Point->ch1_V ) ;
	
	return 0 ;
}

int get_col ( char *in_string, char separator, float *time, float *ch1_V ) {
	char buffer[L_BUFFER_STRING] = {'\n'};
	float value32 = 7.1635E-06;
	float result = 0.0 ;
	int i = 0 ;
	
		 // printf (" Вывод из get_col : \n") ;	// OK
		 // printf ("!!! Separator : %c \n", separator) ; // OK
	
	//float result = strtol(in_string, NULL, 10);
	
	while (( *in_string != separator  ) && ( i < L_BUFFER_STRING ))
	{
		buffer[i] = *in_string ;
		
		*(in_string++) ;
		i++ ;
	}
		buffer[i] = EOL ; *(in_string++) ;

		printf(" \n *buffer :   %s \n", buffer );
		
	*time = strtof(buffer, NULL); // из строки во float
	
	i = 0 ; // *instring продолжает считать
	while (( *in_string != ','  ) && ( i < L_BUFFER_STRING ))
	{
		buffer[i] = *in_string ;
		
		*(in_string++) ;
		i++ ;
	}
		buffer [i] = '\0';*(in_string++) ;

	*ch1_V = strtof(buffer, NULL); // из строки во float

	return 0 ; 

//	sprintf(buffer, "%lu", value32 );

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




void press_AnyKey(void) { // 
												printf("press anykey");
		getchar();
}
