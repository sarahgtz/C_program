#include "person.h"
#include "personlist.h"
#include "bloodrelatives.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc != 6)
    {  fputs ("usage: programm <personfile> <standfile> <vorname> <nachname> <geburtsjahr>\n", stderr);
        exit (1);
    }
    PersonList *pList = newPersonList();
    readPersonList(pList, argv[1]);
    Id *id = newId(argv[3], argv[4], atoi(argv[5]));
    PersonList *bloodRel = findBloodRelatives(pList, id);
    sortBloodRelatives(bloodRel);
    writePersonList(bloodRel, "verwandte.dat");
    deletePersonList(pList);
    deleteBloodRelatives(bloodRel);
    deleteId(id);
    return 0;
}
