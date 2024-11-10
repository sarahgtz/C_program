#include "id.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Id *newId(char *firstname, char *lastname, int birthyear) {
    Id *id = malloc(sizeof(Id));
    if (id == NULL) { exit(1); }

    strcpy(id->firstname, firstname);
    strcpy(id->lastname, lastname);
    id->birthyear = birthyear;
    return id;
}

void deleteId(Id *id) {
    free(id);
}

bool compareId(const Id *id1, const Id *id2) {
    return strcmp(id1->firstname, id2->firstname) == 0
        && strcmp(id1->lastname, id2->lastname) == 0
        && id1->birthyear == id2->birthyear;
}
