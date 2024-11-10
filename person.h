#include <stdio.h>
#include "id.h"
#ifndef PERSON_H
#define PERSON_H

/* A Person stores their own unique ID, their father's ID and their mother's ID */
typedef struct {
    Id *ownId;
    Id *fatherId;
    Id *motherId;
    int mark; // 0 = unmarked, 1=ancestor, 2=descendant
} Person;

Person *newPerson(Id *ownId, Id *fatherId, Id *motherId);
void deletePerson(Person *person);
void printPerson(const Person *person, FILE *output);

#endif
