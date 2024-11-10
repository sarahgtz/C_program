#include "personlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PersonList *newPersonList() {
    PersonList *pList = malloc(sizeof(PersonList));
    pList->count = 0;
    pList->allocated = 10;
    pList->people = (Person **) calloc(pList->allocated, sizeof(Person *));
    return pList;
}

void deletePersonList(PersonList *pList) {
    int i;
    for (i = 0; i < pList->count; i++) deletePerson(pList->people[i]);
    free(pList->people);
    free(pList);
}

void addPerson(PersonList *pList, Person *person) {
    if (pList->count >= pList->allocated) {
        pList->allocated *= 2;
        pList->people = (Person **) realloc (pList->people, pList->allocated * sizeof(Person *));
    }
    pList->people[pList->count++] = person;
}

void readPersonList(PersonList *pList, char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) { perror(fileName); exit(1); }

    char firstname[101], lastname[101], gender;
    int birthyear, deathyear;

    while (fscanf(file, "%100s %100s %c %d %d", firstname, lastname, &gender, &birthyear, &deathyear) != EOF) {
        Id *ownId = newId(firstname, lastname, birthyear);
        fscanf(file, "%100s %100s %d", firstname, lastname, &birthyear);
        Id *fatherId = newId(firstname, lastname, birthyear);
        fscanf(file, "%100s %100s %d", firstname, lastname, &birthyear);
        Id *motherId = newId(firstname, lastname, birthyear);
        Person *person = newPerson(ownId, fatherId, motherId);
        addPerson(pList, person);
    }

    fclose(file);
}

Person *findPerson(PersonList *pList, Id *id) {
    int i;
    for (i = 0; i < pList->count; i++) {
        Id *currentId = pList->people[i]->ownId;
        if (compareId(currentId, id)) {
            return pList->people[i];
        }
    }
    fprintf(stderr, "Person named %s %s, born %d not found\n", id->firstname, id->lastname, id->birthyear);
    exit(1);
}

void printPersonList(PersonList *pList, FILE *output) {
    int i;
    for (i = 0; i < pList->count; i++) {
        Person *person = pList->people[i];
        printPerson(person, output);
    }
}

void writePersonList(PersonList *pList, char *fileName) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) { perror(fileName); exit(1); }
    printPersonList(pList, file);
    fclose(file);
}
