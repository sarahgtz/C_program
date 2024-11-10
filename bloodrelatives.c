#include "bloodrelatives.h"
#include <stdlib.h>
#include <string.h>

void deleteBloodRelatives(PersonList *bloodRel) {
    free(bloodRel->people);
    free(bloodRel);
}

void markAncestors(PersonList *pList, Person *person) {
    if (person == NULL || person->mark == 1) return;
    person->mark = 1;

    int i;
    for (i = 0; i < pList->count; i++) {
        Person *current = pList->people[i];
        if (compareId(current->ownId, person->fatherId) || compareId(current->ownId, person->motherId)) {
            markAncestors(pList, current);
        }
    }
}

void markDescendants(PersonList *pList, Person *person) {
    if (person == NULL || person->mark == 2) return;
    person->mark = 2;

    int i;
    for (i = 0; i < pList->count; i++) {
        Person *current = pList->people[i];
        if (compareId(current->fatherId, person->ownId) || compareId(current->motherId, person->ownId)) {
            markDescendants(pList, current);
        }
    }
}

PersonList *findBloodRelatives(PersonList *pList, Id *id) {
    PersonList *bloodRel = newPersonList();
    Person *startPerson = findPerson(pList, id);

    markAncestors(pList, startPerson);

    int i;
    for (i = 0; i < pList->count; i++) {
        if (pList->people[i]->mark == 1) {
            markDescendants(pList, pList->people[i]);
        }
    }
    for (i = 0; i < pList->count; i++) {
        if (pList->people[i]->mark != 0) {
            addPerson(bloodRel, pList->people[i]);
        }
    }
    return bloodRel;
}

int personOrder(const void *a, const void *b) {
    int comp;
    Person *persA = *(Person **) a;
    Person *persB = *(Person **) b;

    if (persA == persB) return 0;
    if (persA->ownId->birthyear < persB->ownId->birthyear) return -1;
    if (persA->ownId->birthyear > persB->ownId->birthyear) return 1;
    comp = strcmp(persA->ownId->lastname, persB->ownId->lastname);
    if (comp != 0) return comp;
    comp = strcmp(persA->ownId->firstname, persB->ownId->firstname);
    if (comp != 0) return comp;
    return 10;
}

void sortBloodRelatives(PersonList *bloodRel) {
    qsort(bloodRel->people, bloodRel->count, sizeof (Person *), &personOrder);
}
