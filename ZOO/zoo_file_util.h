#ifndef ZOO_FILE_UTIL_H
#define ZOO_FILE_UTIL_H

#define __STDC_LIMIT_MACROS 1
#include <stdio.h>
#include <stdint.h>

#include "bidir_list.h"

typedef enum {
    SORT_BY_NAME    = 0x01,
    SORT_BY_SPECIES = 0x02,
    SORT_WEIGHT     = 0x03,
    SORT_BY_AGE     = 0x04
} sort_criteria;

typedef enum {
   ASCENDING_DIR = 0x55,
   DECREASINNG_DIR = 0xAA
} sort_dir;


typedef struct
{
    unsigned int start_of_list;
    unsigned int start_of_holes;
    unsigned int amount_of_holes;
    unsigned int amount_of_elements;
    char curr_sort_criteria;

} block_of_system_data;


void record_the_file (bidir_list* LIST_DATA, const char* str_path);
unsigned int get_start_of_list(FILE* f);
unsigned int get_start_of_holes(FILE* f);
unsigned int get_amount_of_holes(FILE* f);
unsigned int get_amount_of_elements(FILE* f);

sort_criteria get_curr_sort_criteria(FILE* f);
sort_dir get_cur_sort_dir(FILE* f);


void create_file_and_init_system_data (const char* name);
#endif // ZOO_FILE_UTIL_H

