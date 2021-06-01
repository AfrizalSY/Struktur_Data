#ifndef LIST_PEMAIN_H_INCLUDED
#define LIST_PEMAIN_H_INCLUDED
#include <iostream>
using namespace std;
typedef string infotype_pemain;
typedef struct elmPemain *address_pemain;
struct elmPemain{
    infotype_pemain info;
    address_pemain next;
};
struct list_pemain{
    address_pemain first;
    address_pemain last;
};
void createList(list_pemain &lp);
void printInfo(list_pemain lp);
void insertFirst(list_pemain &lp, infotype_pemain x);
void deleteElm(list_pemain &lp, address_pemain &p);
void deleteFirst(list_pemain &lp, address_pemain &p);
void deleteAfter(list_pemain &lp, address_pemain prec, address_pemain &p);
void deleteLast(list_pemain &lp, address_pemain &p);
address_pemain findElm(list_pemain lp, infotype_pemain x);
int countPemain(list_pemain lp);
#endif // LIST_PEMAIN_H_INCLUDED
