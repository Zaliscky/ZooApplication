#include "zoo_file_util.h"
#include "bidir_list.h"
#include "bidir_list_element.h"
#include "zoo_animal.h"
#include "zoo_file_util.h"

static int adding_list_element_to_file (bidir_list_element* a, FILE* file);

unsigned int get_start_of_list(FILE* f)
{
    unsigned int old_cursor = ftell(f);
    block_of_system_data temp;

    fseek(f, 0, SEEK_SET);
    fread (&temp, sizeof(block_of_system_data) , 1, f);
    fseek(f, old_cursor, SEEK_SET);

    return temp.start_of_list;

}
////////////////////////////////////////////////////////////
unsigned int get_start_of_holes(FILE* f)
{
    unsigned int old_cursor = ftell(f);
    block_of_system_data temp;

    fseek (f, 0, SEEK_SET);
    fread (&temp, sizeof(block_of_system_data), 1, f);
    fseek (f, old_cursor, SEEK_SET);

    return temp.start_of_holes;
}
////////////////////////////////////////////////////////////
unsigned int get_amount_of_holes(FILE* f)
{
    unsigned int old_cursor = ftell(f);
    block_of_system_data temp;

    fseek (f, 0, SEEK_SET);
    fread (&temp, sizeof(block_of_system_data), 1, f);
    fseek (f, old_cursor, SEEK_SET);

    return temp.amount_of_holes;
}
////////////////////////////////////////////////////////////
unsigned int get_amount_of_elements(FILE* f)
{
    unsigned int old_cursor = ftell(f);
    block_of_system_data temp;

    fseek (f, 0, SEEK_SET);
    fread (&temp, sizeof(block_of_system_data), 1, f);
    fseek (f, old_cursor, SEEK_SET);

    return temp.amount_of_elements;
}
////////////////////////////////////////////////////////////

sort_criteria get_curr_sort_criteria(FILE* f)
{
    unsigned int old_cursor = ftell(f);
    block_of_system_data temp;

    fseek (f, 0, SEEK_SET);
    fread (&temp, sizeof(block_of_system_data), 1, f);
    fseek (f, old_cursor, SEEK_SET);

    return sort_criteria(temp.curr_sort_criteria);
}


/////////////////////////////////////////////////////////////

void create_file_and_init_system_data (const char* name)
{
    FILE* fp = NULL;

    fp = fopen (name, "w+");

    if (fp != NULL)
    {
        block_of_system_data temp;

        temp.amount_of_elements = 0;
        temp.amount_of_holes = 0;
        temp.curr_sort_criteria = (char) SORT_BY_NAME;
        temp.start_of_holes = UINT32_MAX;
        temp.start_of_list = UINT32_MAX;

        fseek(fp, 0, SEEK_SET);
        fwrite(& temp, sizeof(block_of_system_data), 1, fp);
       printf("Size of system data %d \n", sizeof(block_of_system_data));
        fclose(fp);
    }

  //  getchar();
 //   getchar();

}


void record_the_file (bidir_list* LIST_DATA , const char* str_path)
{

    bidir_list_element* bidir_element_pointer = LIST_DATA->start;

    FILE* my_file = NULL;

    create_file_and_init_system_data(str_path);
    my_file = fopen(str_path, "rw+");

int a = 0;

printf ("Recording the file\n");

        if (my_file == NULL)
            printf("Error ! Could not open file !\n");
        else

        {

            for (int i = 0; i < LIST_DATA->amount_of_elements; i++)

            {
            fseek(my_file,0, SEEK_END);
            a += adding_list_element_to_file(bidir_element_pointer, my_file);
                    bidir_element_pointer = bidir_element_pointer->next;

             }

            fclose (my_file);
            printf ("Total busy memory : %d", a);

}
    }

static int adding_list_element_to_file (bidir_list_element* a, FILE* file)
{
    int offset_stub = -1;
    int current_size = -1;
    //1)
    int pos = ftell(file);
    fwrite(& offset_stub, sizeof(int), 1, file);
    fwrite(& current_size, sizeof(int), 1, file);
    //2)
    current_size = printing_zoo_animal ( (zoo_animal*)(a->data),file );
    //3)
    //fseek (file, -(current_size + sizeof(int)), SEEK_CUR);
    fseek (file, pos + sizeof(int), SEEK_SET);
    fwrite (&current_size, sizeof(int), 1, file);
    //4)
    fseek(file, pos, SEEK_SET);
    return current_size + 2 * sizeof(int);
}

