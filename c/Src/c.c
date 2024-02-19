#include <stdio.h>
#include "stdbool.h"

int getc_from_file();  


int file_open ( FILE** , char*);

int file_printf ( FILE* , char* );


int file_open ( FILE* *file , char argv[] ){

	char str[512] = {'0'};

	if ((*file = fopen(argv, "r")) == NULL){
							       printf("Не удалось открыть файл");
										       getchar();
			
								   		     	return 1;
	}
									printf("файл открыт \n");	
							     printf("вывод строк из файла \n" ) ;
	getchar();

		while (
				fgets(str, 512, *file) != NULL 
		)

		{
				 printf("%s\n", str ) ;
		}

    	getchar();

    	fclose(*file);

								     printf (" \nFile closed \n");

		return 0 ;
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



int main (int argc, char *argv[]){

	char str[512] = {'\n'};
	FILE *fp;
	int i = 0 ;	
	  
	  file_open ( &fp, argv[1] ) ;

	  printf (" \nFile opened \n");

  	  while 	(	((str[i] = fgetc(fp)) != EOF) 
					&
					( i < 512 )
				)
			{
				printf (" str[i] = %s , i = %d", str[i],i);

				if (str[i] == ',') {
							str[i] = '\0';
							printf("%s\n", str);
			    				i = 0;
		    				    }
				    else { i++; } 
			        }		
	    str[i] = '\0';
	    printf("%s\n",str);
	    printf("i=%d\n",i);

    	    fclose(fp);
	    getchar();

//		getc_from_file(); 

	 return 0 ;
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



