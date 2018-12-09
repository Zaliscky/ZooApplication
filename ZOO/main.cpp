
#include "zoo_file_util.h"
#include "bidir_list.h"
#include "bidir_list_element.h"
#include "zoo_animal.h"
#include "zoo_file_util.h"


int main(int argc, char *argv[])
{
    create_file_and_init_system_data ("./test.inz");


  bidir_list* my_list_point = default_initializer(compare_animals_by_name_acs );

    int curr_key ;
    do
    {
        printf("Choose the action.\n");
        printf("1 Add  element to start in bidirectional list\n");
        printf("2 Add  element to end in bidirectional list\n");
        printf("3 Delete element from bidirectional list by index\n");
        printf("4 Printing bidilist \n");
        printf("5 Default initialization\n");
        printf("6 Get quantity of elements\n");
        printf("7 Resorting of the list\n");
        printf("8 Add to sort list\n");
        printf ("9 Record data \n");
        scanf ("%d", &curr_key);
        fflush(stdin);

        switch (curr_key)
        {
        case 1:
            {
                zoo_animal* new_element;
                new_element = default_constructor ();
                printf ("Input animal:\n");
                inputing_zoo_animal(new_element, stdin);
                printing_zoo_animal(new_element, stdout);
                add_element_start(my_list_point, new_element);

            }
            break;
        case 2 :
            {
                zoo_animal* new_element;
                new_element = default_constructor();
                printf ("Input animal:\n");
                inputing_zoo_animal(new_element, stdin);
                printing_zoo_animal(new_element,stdout);
                add_element_end(my_list_point,new_element);
            }
            break;

        case 3:
            {
                int z;
                printf("Choose the position of deleting element ");
                scanf ("%d", &z);
                remove_elements_at(my_list_point, z);
                bidir_list_output(my_list_point);
            }
            break;

        case 4:
            {
                bidir_list_output(my_list_point);
            }
            break;
        case 5:
            {
                zoo_animal* magru =  NULL;
                magru = initialization_constructor("Kitten", "Myaukovich", 1, 10);
                add_to_sort_list(my_list_point, magru);                bidir_list_output(my_list_point);
                magru = initialization_constructor("Petr", "Murlikin", 5, 20);
                add_to_sort_list(my_list_point, magru);                bidir_list_output(my_list_point);
                magru = initialization_constructor("Elephant", "Big", 15, 1243);
                add_to_sort_list(my_list_point, magru);                bidir_list_output(my_list_point);
                magru = initialization_constructor("Dog", "Naughty", 3, 50);
                add_to_sort_list(my_list_point, magru);                bidir_list_output(my_list_point);
                magru = initialization_constructor("Murzik", "Barsikovich", 0.3 , 4);
                add_to_sort_list(my_list_point, magru);                bidir_list_output(my_list_point);
                magru = initialization_constructor("Leviaphan ", "Melvin", 76, 2548);
                add_to_sort_list(my_list_point, magru);                bidir_list_output(my_list_point);
                magru = initialization_constructor("King", "Kong", 45, 234);
                add_to_sort_list(my_list_point, magru);                bidir_list_output(my_list_point);
            }
            break;

        case 6:
            {
                printf("%d/n", my_list_point->amount_of_elements);
            }
            break;

        case 7:
            {
                int sort_key;
                do
                {
                    printf (" Choose the direction of sorting \n");
                    printf ("============================================================\n");
                    printf ("Press 1 if you want ascending sorting by name\n");
                    printf ("Press 2 if you want decreasing sorting by name \n");
                    printf ("-------------------------------------------------------------\n");
                    printf ("Press 3 if you want ascending sorting by specie\n ");
                    printf ("Press 4  if you want decreasing sorting by specie\n");
                    printf ("-------------------------------------------------------------\n");
                    printf ("Press 5 if you want  sorting by age\n ");
                    printf ("Press 6  if you want  sorting by weight\n");
                    scanf ("%d", &sort_key);
                    fflush(stdin);

                    switch (sort_key)

                    {
                    case 1:
                        {

                            resorting_of_the_list (my_list_point, compare_animals_by_name_acs);


                            bidir_list_output(my_list_point);

                        }
                        break;


                    case 2:
                        {

                            resorting_of_the_list (my_list_point, compare_animals_by_name_desc);

                            bidir_list_output(my_list_point);
                        }
                        break;

                    case 3 :
                        {

                            resorting_of_the_list (my_list_point, compare_animals_by_specie_asc);

                            bidir_list_output(my_list_point);
                        }

                        break;
                    case 4:
                        {
                            resorting_of_the_list (my_list_point, compare_animals_by_specie_dec);

                            bidir_list_output(my_list_point);
                        }
                        break;

                    case 5:
                        {


                            resorting_of_the_list (my_list_point,  compare_animals_by_age);

                            bidir_list_output(my_list_point);
                        }
                        break;

                    case 6:
                        {
                            resorting_of_the_list (my_list_point,  compare_animals_by_weight);

                            bidir_list_output(my_list_point); }
                        break;
                    }
                }
                while (1);


        } break;

        case 8:
            {
            zoo_animal* new_element = NULL;
            new_element = default_constructor ();
            inputing_zoo_animal(new_element, stdin);
            add_to_sort_list(my_list_point,new_element);

        }
            break;

        case 9:
            {
                record_the_file(my_list_point, "Z:\\bidir_list.txt");
                printf ("You  just have recorded the file/n ");
            }
            break;
        }


    } while (1);


    return 0;
}
