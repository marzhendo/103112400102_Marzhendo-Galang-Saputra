#include "ListAngka.h"

bool isEmpty(linkedList L) {
    return L.First == Nil;
}

void CreateList(linkedList &L) {
    L.First = Nil;
}

address alokasi(dataAngka x) {
    address nodeBaru = new node;
    nodeBaru->Angka = x;
    nodeBaru->Next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->Next = Nil;
    delete node;
}

void insertFirst(linkedList &L, address nodeBaru) {
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertAfter(linkedList &L, address nodeBaru, address nodePrev) {
    if (nodePrev != Nil) {
        nodeBaru->Next = nodePrev->Next;
        nodePrev->Next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &L, address nodeBaru) {
    if (isEmpty(L)) {
        L.First = nodeBaru;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu->Next != Nil) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void delAfter(linkedList &L, address nodeHapus, address nodePrev) {
    if (isEmpty(L) == false) {
        if (nodePrev != Nil && nodePrev->Next != Nil) {
            nodePrev->Next = nodeHapus->Next;
            nodeHapus->Next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList L) {
    if (isEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu != Nil) {
            cout << nodeBantu->Angka << " - ";
            nodeBantu = nodeBantu->Next;
        }
        cout << endl;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address nodeBantu = L.First;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->Next;
    }
    return count;
}