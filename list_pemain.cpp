#include "list_pemain.h"
void createList(list_pemain &lp){
    lp.first = NULL;
    lp.last = NULL;
}
void printInfo(list_pemain lp){
    address_pemain p = lp.first;
    if(p != NULL){
        cout << "Daftar pemain : " << endl;
        while(p != NULL){
            cout << p->info << endl;
            p = p->next;
        }
    }else{
        cout << "Pemain tidak ditemukan" << endl;
    }
    cout << endl;
}
void insertFirst(list_pemain &lp, infotype_pemain x){
    address_pemain p = new elmPemain;
    p->info = x;
    p->next = NULL;
    if(lp.first == NULL){
        lp.first = p;
        lp.last = p;
    }else{
        p->next = lp.first;
        lp.first = p;
    }

}
void deleteElm(list_pemain &lp, address_pemain &p){
    if(lp.first == lp.last)
    {
        deleteFirst(lp,p);
    }
    else
    {
        address_pemain q = lp.first;
        address_pemain r = q;
        while(q->next != NULL && q->info != p->info)
        {
            r = q;
            q = q->next;

        }
        if(q == lp.first)
        {
            deleteFirst(lp,p);
        }
        else if(q == lp.last)
        {
            deleteLast(lp,p);
        }
        else
        {
            deleteAfter(lp,r,p);
        }
    }
}
void deleteFirst(list_pemain &lp, address_pemain &p){
    if(lp.first != NULL){
        p = lp.first;
        if(lp.first->next == NULL){
            lp.first = NULL;
            lp.last = NULL;
        }else{
            lp.first = p->next;
        }
    }
}
void deleteAfter(list_pemain &lp, address_pemain prec, address_pemain &p){
    if(prec != NULL)
    {
        if(prec->next == lp.last)
        {
            p = lp.last;
            lp.last = prec;
            lp.last->next = NULL;
        }
        else
        {
            p = prec->next;
            prec->next = p->next;
        }
    }
}
void deleteLast(list_pemain &lp, address_pemain &p){
     if(lp.first != NULL)
    {
        if(lp.first == lp.last)
        {
            p = lp.first;
            lp.first = NULL;
            lp.last = NULL;
        }
        else
        {
            address_pemain q = lp.first;
            while(q->next != lp.last)
            {
                q = q->next;

            }
            p = lp.last;
            lp.last = q;
            q->next = NULL;
        }
    }
}
address_pemain findElm(list_pemain lp, infotype_pemain x){
    address_pemain p = lp.first;
    if(lp.first != NULL){
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
int countPemain(list_pemain lp){
    int i = 0;
    address_pemain p = lp.first;
    while(p != NULL){
        i++;
        p = p->next;
    }
    return i;
}
