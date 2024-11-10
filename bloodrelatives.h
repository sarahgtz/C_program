#include "personlist.h"
#ifndef BLOODRELATIVES_H
#define BLOODRELATIVES_H

void deleteBloodRelatives(PersonList *bloodRel);
PersonList *findBloodRelatives(PersonList *pList, Id *id);
void sortBloodRelatives(PersonList *bloodRel);

#endif
