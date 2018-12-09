#include "bidir_list_element.h"

////////////////////////////////////////////////////////////
////////////////Automatic properties
///////////////Getters
void* bidir_list_element_get_data(bidir_list_element* point)
{
 return point->data;
}


bidir_list_element* bidir_list_element_get_next(bidir_list_element* point)
{
    return point->next;
}

bidir_list_element* bidir_list_element_get_prev(bidir_list_element* point)
{
    return point->prev;
}

////////////////////////////////////////////////////////////Setters

void bidir_list_element_set_data (bidir_list_element* point ,void* new_data)
{
    point->data = new_data;
}

void bidir_list_element_set_next(bidir_list_element* point ,bidir_list_element* modern_element_1 )
{
point->next = modern_element_1;
}

void bidir_list_element_set_prev (bidir_list_element* point , bidir_list_element* modern_element_2)
{
point->prev = modern_element_2;
}



bidir_list_element* bidir_list_element_create(void* new_data)
{
    bidir_list_element* point = NULL;
    point = (bidir_list_element*)malloc(sizeof(bidir_list_element));

    point->next = NULL;
    point->prev = NULL;
    point->data = new_data;

    return point;
}




// #endif // BIDIR_LIST_ELEMENT_H
