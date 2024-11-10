#include <stdbool.h>
#ifndef ID_H
#define ID_H

/* A person's unique identification made of firstname, lastname, birth year */
typedef struct {
    char firstname[101];
    char lastname[101];
    int birthyear;
} Id;

Id *newId(char *firstname, char *lastname, int birthyear);
bool compareId(const Id *id1, const Id *id2);
void deleteId(Id *id);

#endif
