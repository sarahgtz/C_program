#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Person *newPerson(Id *ownId, Id *fatherId, Id *motherId) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) { exit(1); }
    person->ownId = ownId;
    person->fatherId = fatherId;
    person->motherId = motherId;

    person->mark = 0;
    return person;
}

void deletePerson(Person *person) {
    if (person->ownId) free(person->ownId);
    if (person->fatherId) free(person->fatherId);
    if (person->motherId) free(person->motherId);
    free(person);
}

void printPerson(const Person *person, FILE *output) {
    fprintf(output, "%s %s %d\n", person->ownId->firstname, person->ownId->lastname, person->ownId->birthyear);
}