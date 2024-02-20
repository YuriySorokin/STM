#ifndef CSV_TYPEES_H
#define CSV_TYPEES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#ifndef HAS_CSV
#error "+HAS_CSV"
#endif

#include "csv_const.h"

	typedef struct {
		    char* out_buff; /*result array*/
		        char prev_char;
			    char separator;
			        bool init_done;
				    bool fetch_done;
				        char symbol;
					    uint32_t out_size;
					        uint32_t i;/*char index*/
						    int32_t fetch_index; /*starts from 0; -1 if fetch is not needed*/
						        uint32_t cnt; /*total number of cells*/
							    uint32_t position; /*starts from 0*/
							        CsvState_t state;
								    CsvInput_t input;
	} CsvFsm_t;

#ifdef __cplusplus
}
#endif

#endif /* CSV_TYPEES_H */
