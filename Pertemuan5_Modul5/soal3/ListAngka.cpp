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

void updateFirst(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : ";
        cin >> L.First->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList &L) {
    if (isEmpty(L)) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu->Next != Nil) {
            nodeBantu = nodeBantu->Next;
        }
        cout << "masukkan update data node terakhir : ";
        cin >> nodeBantu->Angka;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList &L, address nodePrev) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->Next != Nil) {
            address nodeBantu = nodePrev->Next;
            cout << "masukkan update data node setelah " << nodePrev->Angka << " : ";
            cin >> nodeBantu->Angka;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid atau tidak memiliki node setelahnya!" << endl;
        }
    }
}

void SearchByData(linkedList L, dataAngka data) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->Angka == data) {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->Next;
        }
        if (found == false) {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void SearchByAddress(linkedList L, address node) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nilai : " << nodeBantu->Angka << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->Next;
        }
        if (found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void SearchByRange(linkedList L, dataAngka nilaiMin) {
    if (isEmpty(L)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = L.First;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            if (nodeBantu->Angka >= nilaiMin) {
                cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << nodeBantu->Angka << endl;
                found = true;
            }
            nodeBantu = nodeBantu->Next;
        }
        if (found == false) {
            cout << "Tidak ada data diatas nilai " << nilaiMin << "!" << endl;
        }
    }
    cout << endl;
}

