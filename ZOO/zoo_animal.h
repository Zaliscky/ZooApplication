#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H

#include <stdio.h>
#include <string.h>


typedef struct
{
    char* name;
    char* species;
    float weight;
    float age;

} zoo_animal;

typedef int (*cmp_animals) (const zoo_animal*,const zoo_animal*);



int printing_zoo_animal (zoo_animal* pet, FILE* where);
int inputing_zoo_animal (zoo_animal* pet, FILE* from);
zoo_animal* default_constructor (void);
zoo_animal* initialization_constructor (const char* a,const char* b, const float c, const float d);



int compare_animals_by_name_acs (const zoo_animal* a, const zoo_animal* b);
int compare_animals_by_name_desc (const zoo_animal* a, const zoo_animal* b);

int compare_animals_by_specie_dec(const zoo_animal* a,const zoo_animal* b);
int compare_animals_by_specie_asc(const zoo_animal* a, const zoo_animal* b);
int compare_animals_by_weight (const zoo_animal* a,const zoo_animal* b);
int compare_animals_by_age (const zoo_animal* a,const zoo_animal* b);

void output();
//void fill();


#endif // ZOO_ANIMAL_H

