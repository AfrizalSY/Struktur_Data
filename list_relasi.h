#ifndef LIST_RELASI_H_INCLUDED
#define LIST_RELASI_H_INCLUDED
#include <iostream>

using namespace std;
#include "list_pemain.h"
typedef struct elmRelasi *address_relasi;
struct elmRelasi{
    address_pemain info;
    address_relasi next;
};
struct list_relasi{
    address_relasi first;
    address_relasi last;
};
void createList(list_relasi &lr);
void printInfo(list_relasi lr);
void insertFirst(list_relasi &lr, address_pemain x);
void deleteElm(list_relasi &lr, address_relasi &p);
void deleteFirst(list_relasi &lr, address_relasi &p);
void deleteAfter(list_relasi &lr, address_relasi prec, address_relasi &p);
void deleteLast(list_relasi &lr, address_relasi &p);
address_relasi findElm(list_relasi lr, address_pemain x);

#endif // LIST_RELASI_H_INCLUDED
