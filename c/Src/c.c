#include <stdio.h>

int main (int argc, char *argv[]){

	printf("%d\n",argc);

	
	while ( argc-- )

	{
	       	printf(" argc=%d\n",argc);
		printf(" argv[argc]=%s\n", argv[argc]);
		

	}

	  FILE *fp;
	      if ((fp = fopen(argv[1], "r")) == NULL){
				    printf("Не удалось открыть файл");
				        getchar();
					    return 1;
		}
	      // открыть файл удалось
	      // ...      // требуемые действия над данными
		printf("файл открыт \n");	





		fclose(fp);
		         getchar();

	return 0 ;
}

bool csv_parse_text(const char* const text,
                    char separator, 
                    uint32_t index, 
                    char* const sub_str,
                    uint32_t sub_str_size) {




}





