#ifndef CSV_H
#define CSV_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#include "csv_types.h"

	uint32_t csv_cnt(const char* const text,
			                 char separator);
	bool csv_parse_text(const char* const in_text, 
		            char separator, 
		            uint32_t index, 
		            char* const text,
		            uint32_t size);
	  
#ifdef __cplusplus
}
#endif

#endif /* CSV_H */
