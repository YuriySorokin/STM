#ifndef CSV_CONST_H
#define CSV_CONST_H


#ifndef HAS_CSV
#error "+HAS_CSV"
#endif

typedef enum {
	    CSV_STATE_INIT = 1,
	        CSV_STATE_ACCUMULATE = 2,
		    CSV_STATE_SEP = 3,
		        CSV_STATE_END = 4,
			    CSV_STATE_UNDEF = 0,
} CsvState_t;

typedef enum {
	    CSV_INPUT_NOT_SEP = 1,
	        CSV_INPUT_SEP = 2,
		    CSV_INPUT_END = 3,
		        CSV_INPUT_UNDEF = 0,
} CsvInput_t;

#endif /*CSV_CONST_H*/
