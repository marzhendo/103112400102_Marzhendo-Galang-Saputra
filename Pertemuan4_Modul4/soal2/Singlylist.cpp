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

void deleteFirst(List &L, address &P) {
    //jika list tidak kosong
    if (L.First != Nil) {
        //simpan alamat node pertama ke P
        P = L.First;
        //geser First ke node selanjutnya
        L.First = L.First -> next;
        //putuskan hubungan node P dengan list
        P -> next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        //list kosong
        P = Nil;
    } else if (L.First -> next == Nil) {
        //hanya ada satu elemen
        P = L.First;
        L.First = Nil;
    } else {
        //lebih dari satu elemen
        address Prec = L.First;
        //cari node sebelum node terakhir
        while (Prec -> next -> next != Nil) {
            Prec = Prec -> next;
        }
        //Prec sekarang adalah node sebelum terakhir
        P = Prec -> next; //node terakhir
        Prec -> next = Nil;
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec -> next != Nil) {
        P = Prec -> next; //node yang akan dihapus
        Prec -> next = P -> next; //lewati node P
        P -> next = Nil; 
    }
}

int nbList(List L) {
    address P = L.First; 
    int count = 0;
    //loop untuk menghitung node
    while (P != Nil) {
        count++;
        P = P -> next;
    }
    return count;
}

void deleteList(List &L) {
    address P;
    //ulangi deleteFirst sampai list kosong
    while (L.First != Nil) {
        deleteFirst (L, P);
        dealokasi(P); //hapus node
    }

    //cetak pesan jika list sudah kosong
    if (L.First == Nil) {
        cout << "- List Berhasil Terhapus -" << endl;
    }
}