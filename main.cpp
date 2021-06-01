#include <iostream>
#include "list_pemain.h"
#include "list_turnamen.h"
#include "list_relasi.h"
using namespace std;

int main()
{
    list_turnamen lt;
    list_pemain lp;

    int pilihMenu;
    string inputUser;
    address_pemain p;
    address_turnamen t;
    address_relasi r;

    createList(lt);
    createList(lp);
    while(true)
    {
        cout << "MENU" << endl;
        cout << "1. Tambah Turnamen" << endl;
        cout << "2. Tambah Pemain" << endl;
        cout << "3. Tambah Relasi" << endl;
        cout << "4. Hapus turnamen" << endl;
        cout << "5. Hapus pemain" << endl;
        cout << "6. Tampil turnamen beserta pesertanya" << endl;
        cout << "7. Turnamen paling diminati" << endl;
        cout << "8. Pemain paling sedikit mengikuti turnamen" << endl;
        cout << "9. Pemain yang mengikuti turnamen yang sama" << endl;
        cout << "10. Ganti nama turnamen (BONUS 1)" << endl;
        cout << "11. Ganti nama pemain (BONUS 2)" << endl;
        cout << "0. Keluar" << endl;


        cout << "Pilih Menu : ";
        cin >> pilihMenu;
        if(pilihMenu == 1)
        {
            cout << "Masukkan nama Turnamen : " << endl;
            cin >> inputUser;
            while(findElm(lt, inputUser) != NULL)
            {
                cout << "Turnamen sudah ada!" << endl;
                cout << "Masukkan nama Turnamen : ";
                cin >> inputUser;
            }
            insertFirst(lt, inputUser);
            printInfo(lt);
        }
        else if(pilihMenu == 2)
        {
            cout << "Masukkan nama Pemain : " << endl;
            cin >> inputUser;
            while(findElm(lp, inputUser) != NULL)
            {
                cout << "Pemain sudah ada!" << endl;
                cout << "Masukkan nama Pemain : ";
                cin >> inputUser;
            }
            insertFirst(lp, inputUser);
            printInfo(lp);
        }
        else if(pilihMenu == 3)
        {
            if(lp.first != NULL && lt.first != NULL)
            {
                cout << "Masukkan nama Pemain : " << endl;
                cin >> inputUser;
                p = findElm(lp,inputUser);
                while(p == NULL)
                {
                    cout << "Pemain tidak ada!" << endl;
                    cout << "Masukkan nama Pemain : " << endl;
                    cin >> inputUser;
                    p = findElm(lp,inputUser);
                }
                cout << "Masukkan nama Turnamen : " << endl;
                cin >> inputUser;
                t = findElm(lt,inputUser);
                while(t == NULL)
                {
                    cout << "Turnamen tidak ada!" << endl;
                    cout << "Masukkan nama Turnamen : ";
                    cin >> inputUser;
                    t = findElm(lt,inputUser);
                }
                insertFirst(t->relasi,p);
                cout << "Turnamen " << t->info << endl;
                printInfo(t->relasi);
            }
            else
            {
                cout << "Tidak bisa menambah relasi karena turnamen atau pemain tidak ada!" << endl;
            }
        }
        else if(pilihMenu == 4)
        {
            cout << "Masukkan nama Turnamen : " << endl;
            cin >> inputUser;
            t = findElm(lt,inputUser);
            while(t == NULL)
            {
                cout << "Turnamen tidak ada!" << endl;
                cout << "Masukkan nama Turnamen : ";
                cin >> inputUser;
                t = findElm(lt,inputUser);
            }
            deleteElm(lt,t);
            if(t->relasi.first != NULL)
            {
                while(t->relasi.first != NULL)
                {
                    deleteFirst(t->relasi,r);
                }
            }
            printInfo(lt);
        }
        else if(pilihMenu == 5)
        {
            cout << "Masukkan nama pemain : " << endl;
            cin >> inputUser;
            p = findElm(lp,inputUser);
            while(p == NULL)
            {
                cout << "Pemain tidak ada!" << endl;
                cout << "Masukkan nama pemain : ";
                cin >> inputUser;
                p = findElm(lp,inputUser);
            }
            deleteElm(lp,p);
            address_turnamen adrT = lt.first;
            while(adrT != NULL)
            {
                r = findElm(adrT->relasi,p);
                if(r != NULL)
                {
                    deleteElm(adrT->relasi,r);
                }
            }
            printInfo(lp);
        }
        else if(pilihMenu == 6)
        {
            t = lt.first;
            if(t != NULL)
            {
                while(t != NULL)
                {
                    cout << "Turnamen " << t->info << endl;
                    printInfo(t->relasi);
                    t = t->next;
                }
            }
            else
            {
                cout << "Tidak memiliki turnamen" << endl;
            }
        }
        else if(pilihMenu == 7)
        {
            int max = 0;
            int i;
            address_turnamen x = NULL;
            t = lt.first;
            if(t != NULL)
            {
                while(t != NULL)
                {
                    i = 0;
                    r = t->relasi.first;
                    while(r != NULL)
                    {
                        i++;
                        r = r->next;
                    }
                    if(i > max)
                    {
                        max = i;
                        x = t;
                    }
                    t = t->next;
                }
                if(x != NULL)
                {
                    cout << "Turnamen paling banyak diminati adalah " << x->info << " diikuti sebanyak " << max << " pemain" << endl;
                }
                else
                {
                    cout << "Tidak ada turnamen yang paling banyak diminati" << endl;
                }
            }
            else
            {
                cout << "Tidak ada turnamen yang paling banyak diminati" << endl;
            }
        }
        else if(pilihMenu == 8)
        {
            int min = countTurnamen(lt) + 1;
            int i;
            address_pemain x = NULL;
            p = lp.first;
            while(p != NULL)
            {
                i = 0;
                t = lt.first;
                while(t != NULL)
                {
                    if(findElm(t->relasi,p) != NULL)
                    {
                        i++;
                    }
                    t = t->next;
                }
                if(i < min)
                {
                    min = i;
                    x = p;
                }
                p = p->next;
            }
            if(x != NULL)
            {
                cout << "Pemain yang paling sedikit mengikuti turnamen adalah " << x->info << " hanya mengikuti " << min << " turnamen" << endl;
            }
            else
            {
                cout << "Pemain paling sedikit mengikuti turnamen tidak ditemukan" << endl;
            }
        }
        else if(pilihMenu == 9)
        {
            p = lp.first;
            address_pemain x;
            bool sama = false;
            bool ada = false;
            while(p != NULL)
            {
                x = p->next;
                while(x != NULL)
                {
                    sama = true;
                    t = lt.first;
                    while(t != NULL)
                    {
                        sama = findElm(t->relasi,p) != NULL && findElm(t->relasi,x) != NULL;
                        t = t->next;
                    }
                    if(sama)
                    {
                        ada = true;
                        cout << p->info << " dan " << x->info << " mengikuti turnamen yang sama" << endl;
                    }
                    x = x->next;
                }
                p = p->next;
            }
            if(!ada)
            {
                cout << "Tidak ada pemain dengan turnamen yang sama" << endl;
            }
        }
        else if(pilihMenu == 10)
        {
            cout << "Masukkan nama turnamen : " << endl;
            cin >> inputUser;
            t = findElm(lt,inputUser);
            while(t == NULL)
            {
                cout << "Turnamen tidak ada!" << endl;
                cout << "Masukkan nama turnamen : ";
                cin >> inputUser;
                t = findElm(lt,inputUser);
            }
            cout << "Masukkan nama baru : " << endl;
            cin >> inputUser;
            address_turnamen x = findElm(lt,inputUser);
            while(x != NULL)
            {
                cout << "Turnamen sudah ada!" << endl;
                cout << "Masukkan nama baru : ";
                cin >> inputUser;
                x = findElm(lt,inputUser);
            }
            t->info = inputUser;
            cout << "Nama turnamen berhasil diganti" << endl;
        }
        else if(pilihMenu == 11)
        {
            cout << "Masukkan nama pemain : " << endl;
            cin >> inputUser;
            p = findElm(lp,inputUser);
            while(p == NULL)
            {
                cout << "Turnamen tidak ada!" << endl;
                cout << "Masukkan nama pemain : ";
                cin >> inputUser;
                p = findElm(lp,inputUser);
            }
            cout << "Masukkan nama baru : " << endl;
            cin >> inputUser;
            address_pemain x = findElm(lp,inputUser);
            while(x != NULL)
            {
                cout << "Turnamen sudah ada!" << endl;
                cout << "Masukkan nama baru : ";
                cin >> inputUser;
                x = findElm(lp,inputUser);
            }
            p->info = inputUser;
            cout << "Nama pemain berhasil diganti" << endl;

        }
        else if(pilihMenu == 0)
        {
            cout << "TERIMA KASIH" << endl;
            break;

        }
        else
        {
            cout << "Pilih menu dengan benar!" << endl;
        }
    }
    return 0;
}
