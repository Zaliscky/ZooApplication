#include "bidir_list.h"
#include "zoo_animal.h"



 bidir_list* default_initializer (cmp_animals new_criteria)
{
    bidir_list* point = ((bidir_list*)malloc(sizeof(bidir_list)));
    point->start = NULL;
    point->end = NULL;
    point->amount_of_elements = 0;
    point->current_criteria = new_criteria;
    return point;
}

 int get_amount_of_elements(bidir_list* point)
{
    return point->amount_of_elements;
}

 bidir_list_element* get_start(bidir_list* point)
 {

      return point->start;
 }


bidir_list_element* get_end(bidir_list* point)
 {
      return point->end;
 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
void set_data (void* new_data)
{
    point->data = new_data;
}

void set_next(bidir_list* modern_element_1)
{
point->next = modern_element_1;
}

void set_prev (bidir_list* modern_element_2)
{
point->prev = modern_element_2;
}



 void set_criteria (bidir_list* list, cmp_animals new_criteria)
 {
     list->current_criteria = new_criteria;
 }

*/


void add_element_start(bidir_list* list_for_add, void* new_value)
{
    bidir_list_element* new_elem = bidir_list_element_create(new_value);

    switch (list_for_add->amount_of_elements)
    {
    case 0:
        list_for_add->start = new_elem;
        list_for_add->end =  new_elem;
        break;


    default:
        new_elem->next = list_for_add->start;
        list_for_add->start->prev = new_elem;
        list_for_add->start = new_elem;

        break;
    }
    list_for_add->amount_of_elements++;
}


void add_element_end(bidir_list* list_for_add, void* new_value)
{
    bidir_list_element* new_elem =  bidir_list_element_create(new_value);

    switch (list_for_add->amount_of_elements)
    {
    case 0:
        list_for_add->start = new_elem;
        list_for_add->end = new_elem;
        break;


    default:
        new_elem->prev = list_for_add->end;
        list_for_add->end->next = new_elem;
        list_for_add->end = new_elem;
        break;
    }

    list_for_add->amount_of_elements++;
}



void remove_elements_at(bidir_list* list_for_add, int pos)
{
    if ((pos < 0) || (pos > list_for_add->amount_of_elements))
        return ;

    else
    {
        bidir_list_element* wp =  list_for_add->start;

        for (  int i = 0; i < pos; i++)
        {
            wp = wp->next;
        }

        if (wp != list_for_add->start)
            wp->prev->next = wp->next;
        if (wp != list_for_add->end)
            wp->next->prev = wp->prev;

        if (wp == list_for_add->start)
            list_for_add->start = list_for_add->start->next;
        if (wp == list_for_add->end)
            list_for_add->end = list_for_add->end->prev;

        list_for_add->amount_of_elements--;
        free(wp->data);
        free(wp);
    }

}
/////////////////////////////////////////////////////////////////////////////////
void remove_elements_like(bidir_list* list, zoo_animal* origin)
{
    bidir_list_element* wp = list->start;
    long counter = 0;
    while (wp != NULL)
    {
        if ( list->current_criteria( (zoo_animal*)(wp->data), origin) == 0)
            break;
        wp = wp->next;
        counter++;
    }

    if (wp != NULL)  // we have finished finding with result
        remove_elements_at(list ,counter);

}
/////////////////////////////////////////////////////////////////////////////////////

int find_pos_in_sort_list (bidir_list* list, zoo_animal* origin)
{
    bidir_list_element* wp = list->start;
    long counter = 0;
    while (wp != NULL)
    {
        if ( list->current_criteria( (zoo_animal*)(wp->data), origin) > 0)
            break;
        wp = wp->next;
        counter++;
    }

return counter;
}

void add_to_sort_list (bidir_list* list,zoo_animal* origin)
{
    bidir_list_element* ne = bidir_list_element_create(origin);


    // loop for finding
    int quant = find_pos_in_sort_list ( list, origin);
    printf ( "quant :  %d", quant);
    printing_zoo_animal(origin, stdout);
    if (quant == 0){
        add_element_start (list, origin);
    } else if (quant == list->amount_of_elements) {
        add_element_end(list, origin);
    } else {
        bidir_list_element* wp = list->start;

        for (int i = 0 ; i < quant - 1; i++, wp = wp->next);

        ne->prev = wp;
        ne->next = wp->next;
        wp->next = ne;
        ne->next->prev = ne;
        list->amount_of_elements ++;
    }
}

void resorting_of_the_list (bidir_list* list, cmp_animals new_criteria)
{
    bidir_list_element* old_list_start = list->start;
    list->start = NULL;
    list->end = NULL;
    int counter = list->amount_of_elements;
    list->amount_of_elements = 0;
    list->current_criteria = new_criteria;
    for (int i = 0; i < counter; i++)
    {
        bidir_list_element* wp = old_list_start;
        old_list_start = old_list_start->next;

        add_to_sort_list(list, (zoo_animal*)(wp->data));
        free (wp);

    }

}

void bidir_list_output( bidir_list* point)
{

    bidir_list_element* curr_elem = point->start;
    printf ("--------------------------------------------------------------------------------------");
    while (curr_elem != NULL)
    {
        printf("Your current element data: \n");
        printing_zoo_animal((zoo_animal*)(curr_elem->data), stdout);
        curr_elem = curr_elem->next;

    }
        printf ("--------------------------------------------------------------------------------------");
}




