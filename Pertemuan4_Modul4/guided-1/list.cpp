#include <iostream>
#include "list.h"
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nill){
        return true;
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nill;
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru -> isiData.nama = nama;
    nodeBaru -> isiData.nim = nim;
    nodeBaru -> isiData.umur = umur;
    nodeBaru -> next = Nill;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node -> next = Nill;
    delete node;
}

// prosedur untuk insert
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru -> next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nill) {
        nodeBaru -> next = Prev -> next;
        Prev ->  next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu -> next != Nill) {
            nodeBantu = nodeBantu -> next;
        }
        nodeBantu -> next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printlist(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nill) {
            cout << "Nama : " << nodeBantu -> isiData.nama << ", NIM : " << nodeBantu -> isiData.nim << ", Usia : "
            << nodeBantu -> isiData.umur << endl;
            nodeBantu = nodeBantu -> next;
        }
    }
}