#include "list_turnamen.h"
void createList(list_turnamen &lt){
    lt.first = NULL;
    lt.last = NULL;
}
void printInfo(list_turnamen lt){
    address_turnamen p = lt.first;
    if(p != NULL){
        cout << "Daftar turnamen : " << endl;
        while(p != NULL){
            cout << p->info << endl;
            printInfo(p->relasi);
            p = p->next;
        }
    }else{
        cout << "Tidak ada turnamen" << endl;
    }
}
void insertFirst(list_turnamen &lt, infotype_turnamen x){
    address_turnamen p = new elmTurnamen;
    createList(p->relasi);
    p->info = x;
    p->next = NULL;
    if(lt.first == NULL){
        lt.first = p;
        lt.last = p;
    }else{
        p->next = lt.first;
        lt.first = p;
    }
}
void deleteElm(list_turnamen &lt, address_turnamen &p){
    if(lt.first == lt.last)
    {
        deleteFirst(lt,p);
    }
    else
    {
        address_turnamen q = lt.first;
        address_turnamen r = q;
        while(q->next != NULL && q->info != p->info)
        {
            r = q;
            q = q->next;

        }
        if(q == lt.first)
        {
            deleteFirst(lt,p);
        }
        else if(q == lt.last)
        {
            deleteLast(lt,p);
        }
        else
        {
            deleteAfter(lt,r,p);
        }
    }
}
void deleteFirst(list_turnamen &lt, address_turnamen &p){
    if(lt.first != NULL){
        p = lt.first;
        if(lt.first->next == NULL){
            lt.first = NULL;
            lt.last = NULL;
        }else{
            lt.first = p->next;
        }
    }
}
void deleteAfter(list_turnamen &lt, address_turnamen prec, address_turnamen &p){
    if(prec != NULL)
    {
        if(prec->next == lt.last)
        {
            p = lt.last;
            lt.last = prec;
            lt.last->next = NULL;
        }
        else
        {
            p = prec->next;
            prec->next = p->next;
        }
    }
}
void deleteLast(list_turnamen &lt, address_turnamen &p){
    if(lt.first != NULL)
    {
        if(lt.first == lt.last)
        {
            p = lt.first;
            lt.first = NULL;
            lt.last = NULL;
        }
        else
        {
            address_turnamen q = lt.first;
            while(q->next != lt.last)
            {
                q = q->next;

            }
            p = lt.last;
            lt.last = q;
            q->next = NULL;
        }
    }
}
address_turnamen findElm(list_turnamen lt, infotype_turnamen x){
    address_turnamen p = lt.first;
    if(lt.first != NULL){
        while(p != NULL){
            if(p->info == x){
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
    return NULL;
}
int countTurnamen(list_turnamen lt){
    int i = 0;
    address_turnamen p = lt.first;
    while(p != NULL){
        i++;
        p = p->next;
    }
    return i;
}
