#include "Singlylist.h"

void CreateList(List &L) {
    //set pointer First ke Nil
    L.First = Nil;
}

address alokasi(infotype x) {
    //buat node baru
    address P = new ElmList;
    //isi info dan next
    P -> info = x;
    P -> next = Nil;
    return P;
}

void dealokasi(address &P) {
    //hapus node yang ditunjuk P
    delete P;
}

void printInfo(List L) {
    //print info dari setiap node
    address P = L.First;

    if (P == Nil) {
        cout << "List Kosong" << endl;
    } else {
        //selama P bukan Nil, print info dan geser P ke next
        while (P != Nil) {
            //print info diikuti spasi
            cout << P -> info << " ";
            //geser P ke node berikutnya
            P = P -> next;
        }
        //jika sudah selesai, baris akan diakhiri dengan newline
        cout << endl; 
    }
}

void insertFirst(List &L, address P) {
    //arahkan node baru (P) ke node pertama (L.First)
    P -> next = L.First;
    //jadikan node baru (P) sebagai node pertama
    L.First = P;
}