#include "person.h"
#ifndef PERSONLIST_H
#define PERSONLIST_H

/* A list of people stores an array of pointers to Person objects and its size */
typedef struct {
    Person **people;
    int count;
    int allocated;
} PersonList;

PersonList *newPersonList();
void deletePersonList(PersonList *pList);
void addPerson(PersonList *pList, Person *person);
void readPersonList(PersonList *pList, char *fileName);
Person *findPerson(PersonList *pList, Id *id);
void writePersonList(PersonList *pList, char *fileName);

#endif
