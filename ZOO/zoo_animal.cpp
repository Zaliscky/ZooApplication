

#include "zoo_animal.h"
#include "bidir_list.h"
#include "bidir_list_element.h"


int printing_zoo_animal (zoo_animal* pet, FILE* where)
{
    int count = 0;
   count += fprintf(where, "%s\n", pet->name);
   count += fprintf(where, "%s\n", pet->species);
   count += fprintf(where, "%f\n", pet->age);
   count += fprintf(where, "%f\n", pet->weight);

   return count;
}

int inputing_zoo_animal (zoo_animal* pet, FILE* from)
{
    int count = 0;

    char buffer_for_strings[255];

   memset(buffer_for_strings, 0, 255);
   printf ("Input name of animal");
   fgets(buffer_for_strings, 255 , from);
   count += strlen(buffer_for_strings);

   if (pet->name != NULL) // if we have old name of animal
            free(pet->name);
   pet->name = (char*) malloc( sizeof(char)  * (strlen(buffer_for_strings) + 1) ); // + 1 symbol for storing Zero-termination
   strcpy(pet->name, buffer_for_strings);

   memset(buffer_for_strings, 0, 255);
   printf ("Input specie of animal");
   fgets(buffer_for_strings, 255, from);
   count += strlen(buffer_for_strings);

   if (pet->species != NULL) // if we have old name of animal
            free(pet->species);
   pet->species = (char*) malloc( sizeof(char)  * (strlen(buffer_for_strings) + 1) ); // + 1 symbol for storing Zero-termination
   strcpy(pet->species, buffer_for_strings);

   printf ("Input animal's age: ");
   fgets(buffer_for_strings, 255, from);
   pet-> age = (float) atof( buffer_for_strings );
   printf ("Input animal;s weight: ");
   fgets(buffer_for_strings, 255, from);
   pet->weight = (float)atof(buffer_for_strings);



    count += 2 * sizeof(float);


   return count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
zoo_animal* default_constructor (void)
{
    zoo_animal* pet = (zoo_animal*)malloc(sizeof(zoo_animal));
    pet->name = NULL;
    pet->species = NULL;
    pet->weight = 0;
    pet->age = 0;

    return pet;
}

void deconstructor (zoo_animal* pet)
{
    free(pet->name);
    free(pet->species);
    free (pet);
}

zoo_animal* initialization_constructor (const char* a,const char* b, const float c, const float d)
{
    zoo_animal* pet = (zoo_animal* )malloc( sizeof(zoo_animal) );

    pet->name = (char*) malloc( sizeof(char)  * (strlen(a) + 1) ); // + 1 symbol for storing Zero-termination
    memset(pet->name ,0, strlen(a) + 1);
    strcpy(pet->name,a);

    pet->species = (char*) malloc( sizeof(char)  * (strlen(b) + 1) ); // + 1 symbol for storing Zero-termination
     memset(pet->species ,0, strlen(b) + 1);
    strcpy(pet->species,  b);

    pet->weight = c;
    pet->age = d;

    return pet;
}




int compare_animals_by_name_acs (const zoo_animal* a, const zoo_animal* b)
{
    return strcmp (a->name, b ->name);
}

int compare_animals_by_name_desc (const zoo_animal* a, const zoo_animal* b)
{
    return strcmp ( b ->name, a->name);
}
///////////////////////////////////////////////////////////////////////////

int compare_animals_by_specie_asc(const zoo_animal* a,const zoo_animal* b)
{
    return strcmp (a->species, b->species);
}

int compare_animals_by_specie_dec(const zoo_animal* a, const zoo_animal*b)
{
    return strcmp(b->species, a->species);
}

int compare_animals_by_weight (const zoo_animal* a,const zoo_animal* b)
{
  if (a->weight > b->weight)
        return 1;

    else if (a->weight < b->weight)
            return -1;

    else return 0;
}

int compare_animals_by_age (const zoo_animal* a,const zoo_animal* b)
{
    if (a->age > b->weight)
        return 1;
    else if (a->age < b->age)
        return -1;

    else return 0;
}

