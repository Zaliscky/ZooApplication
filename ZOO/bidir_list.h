#ifndef BIDIR_LIST_H
#define BIDIR_LIST_H
#include "bidir_list_element.h"
#include "zoo_animal.h"
struct __bidir_list
{
    int amount_of_elements;
    bidir_list_element* start;
    bidir_list_element* end;
    cmp_animals current_criteria;
};
typedef struct __bidir_list bidir_list;
bidir_list* default_initializer (cmp_animals new_criteria);
int get_amount_of_elements(bidir_list* point);
bidir_list_element* get_start(bidir_list* point);
bidir_list_element* get_end(bidir_list* point);
void set_criteria (bidir_list* list, cmp_animals new_criteria);
void add_to_sort_list (bidir_list* list,zoo_animal* new_element);
void bidir_list_output( bidir_list* point);
void remove_elements_at(bidir_list* list_for_add, int pos);
bidir_list* bidir_list_create(void* new_elem);
void add_element_start(bidir_list* list_for_add, void* new_value);
void resorting_of_the_list (bidir_list* list, cmp_animals new_criteria);
void add_element_end(bidir_list* list_for_add, void* new_value);



#endif // BIDIR_LIST_H
