#include "list_relasi.h"
void createList(list_relasi &lr){
    lr.first = NULL;
    lr.last = NULL;
}
void printInfo(list_relasi lr){
    address_relasi p = lr.first;
    if(p != NULL){
        cout << "Memiliki pemain : " << endl;
        while(p != NULL){
            cout << p->info->info << endl;
            p = p->next;
        }
    }else{
        cout << "Tidak memiliki pemain" << endl;
    }
    cout << endl;
}
void insertFirst(list_relasi &lr, address_pemain x){
    address_relasi p = new elmRelasi;
    p->info = x;
    p->next = NULL;
    if(lr.first == NULL){
        lr.first = p;
        lr.last = p;
    }else{
        p->next = lr.first;
        lr.first = p;
    }
}
void deleteElm(list_relasi &lr, address_relasi &p){
    if(lr.first == lr.last)
    {
        deleteFirst(lr,p);
    }
    else
    {
        address_relasi q = lr.first;
        address_relasi r = q;
        while(q->next != NULL && q->info != p->info)
        {
            r = q;
            q = q->next;

        }
        if(q == lr.first)
        {
            deleteFirst(lr,p);
        }
        else if(q == lr.last)
        {
            deleteLast(lr,p);
        }
        else
        {
            deleteAfter(lr,r,p);
        }
    }
}
void deleteFirst(list_relasi &lr, address_relasi &p){
    if(lr.first != NULL){
        p = lr.first;
        if(lr.first->next == NULL){
            lr.first = NULL;
            lr.last = NULL;
        }else{
            lr.first = p->next;
        }
    }
}
void deleteAfter(list_relasi &lr, address_relasi prec, address_relasi &p){
    if(prec != NULL)
    {
        if(prec->next == lr.last)
        {
            p = lr.last;
            lr.last = prec;
            lr.last->next = NULL;
        }
        else
        {
            p = prec->next;
            prec->next = p->next;
        }
    }
}
void deleteLast(list_relasi &lr, address_relasi &p){
    if(lr.first != NULL)
    {
        if(lr.first == lr.last)
        {
            p = lr.first;
            lr.first = NULL;
            lr.last = NULL;
        }
        else
        {
            address_relasi q = lr.first;
            while(q->next != lr.last)
            {
                q = q->next;

            }
            p = lr.last;
            lr.last = q;
            q->next = NULL;
        }
    }
}
address_relasi findElm(list_relasi lr, address_pemain x){
    address_relasi p = lr.first;
    if(lr.first != NULL){
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
