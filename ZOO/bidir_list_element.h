#ifndef BIDIR_LIST_ELEMENT_H
#define BIDIR_LIST_ELEMENT_H

#include <stdlib.h>

struct __bidir_list_element
{
   struct    __bidir_list_element* next;
   void*    data;
   struct   __bidir_list_element* prev;

};

typedef struct __bidir_list_element bidir_list_element ;

void* bidir_list_element_get_data(bidir_list_element* point);
bidir_list_element* bidir_list_element_get_next(bidir_list_element* point);
bidir_list_element* bidir_list_element_get_prev(bidir_list_element* point);

void bidir_list_element_set_data (bidir_list_element* point ,void* new_data);

void bidir_list_element_set_next(bidir_list_element* point ,bidir_list_element* modern_element_1 );


void bidir_list_element_set_prev (bidir_list_element* point , bidir_list_element* modern_element_2);
bidir_list_element* bidir_list_element_create(void* new_data);
bidir_list_element* bidir_list_element_create(void );



#endif // BIDIR_LIST_ELEMENT_H
