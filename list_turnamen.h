#ifndef LIST_TURNAMEN_H_INCLUDED
#define LIST_TURNAMEN_H_INCLUDED
#include <iostream>

using namespace std;
#include "list_relasi.h"

typedef string infotype_turnamen;
typedef struct elmTurnamen *address_turnamen;
struct elmTurnamen{
    infotype_turnamen info;
    list_relasi relasi;
    address_turnamen next;
};
struct list_turnamen{
    address_turnamen first;
    address_turnamen last;
};
void createList(list_turnamen &lt);
void printInfo(list_turnamen lt);
void insertFirst(list_turnamen &lt, infotype_turnamen x);
void deleteElm(list_turnamen &lt, address_turnamen &p);
void deleteFirst(list_turnamen &lt, address_turnamen &p);
void deleteAfter(list_turnamen &lt, address_turnamen prec, address_turnamen &p);
void deleteLast(list_turnamen &lt, address_turnamen &p);
address_turnamen findElm(list_turnamen lt, infotype_turnamen x);
int countTurnamen(list_turnamen lt);
#endif // LIST_TURNAMEN_H_INCLUDED
