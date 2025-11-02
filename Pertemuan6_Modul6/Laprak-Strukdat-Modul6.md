# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Double Linked List adalah struktur data dinamis yang merupakan pengembangan dari Single Linked List. Pada dasarnya, penggunaan Double Linked List hampir sama dengan penggunaan Single Linked List. Hanya saja Double Linked List menerapkan sebuah pointer baru, yaitu prev, yang digunakan untuk menggeser mundur selain tetap mempertahankan pointer next [61].
Keberadaan 2 pointer penunjuk (next dan prev) menjadikan Double Linked List menjadi lebih fleksibel dibandingkan Single Linked List, namun dengan mengorbankan adanya memori tambahan dengan adanya pointer tambahan tersebut. Ada 2 jenis Double Linked List, yaitu: Double Linked List Non Circular (DLLNC) dan Double Linked List Circular [62].
Double Linked List Non Circular (DLLNC) adalah sebuah Linked List yang terdiri dari dua arah pointer, dengan node yang saling terhubung, namun kedua pointernya menunjuk ke NULL. Setiap node pada linked list mempunyai field yang berisi data dan pointer yang saling berhubungan dengan node yang lainnya [62].
Struktur node pada Double Linked List terdiri dari tiga bagian utama: bagian data yang menyimpan informasi, pointer next yang menunjuk ke node berikutnya, dan pointer prev yang menunjuk ke node sebelumnya. Dengan struktur ini, penelusuran data dapat dilakukan dua arah, yaitu maju (forward) menggunakan pointer next dan mundur (backward) menggunakan pointer prev [62-63].
### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Guided 1

```listBuah.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif

```
```listBuah.cpp
#include "ListMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}


```
```main.cpp
#include "ListMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```
Program Guided 1 ini membuat sistem sederhana untuk menyimpan dan mengelola daftar makanan menggunakan Doubly Linked List (struktur data yang saling terhubung dua arah). Setiap makanan memiliki data berupa nama, jenis, harga, dan rating.

File ListMakanan.h berisi rancangan struktur data dan daftar fungsi yang digunakan. File ListMakanan.cpp berisi isi dari fungsi-fungsi tersebut, seperti membuat list baru, menambah data di awal, akhir, atau di tengah list, menampilkan seluruh isi list, serta mengubah data yang sudah ada.
Sementara main.cpp adalah bagian utama yang menjalankan program. Di sini dibuat beberapa data makanan, lalu data tersebut dimasukkan ke dalam list, ditampilkan, dan diuji proses pengubahannya.

Hasil output program menampilkan daftar makanan sebelum dan sesudah dilakukan proses update. Awalnya data ditampilkan sesuai urutan saat dimasukkan, kemudian setelah pengguna memperbarui data pada posisi tertentu, hasil perubahan langsung terlihat pada tampilan list.
Secara sederhana, program ini membantu memahami bagaimana cara menambah, menampilkan, dan mengubah data pada struktur linked list, serta menunjukkan cara kerja hubungan dua arah antar node dalam penyimpanan data dinamis.

### 2. Guided 2

```listBuah.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif

```
```listBuah.cpp
#include "ListMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}


```
```main.cpp
#include "ListMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```
Program Guided 2 ini merupakan pengembangan dari Guided 1 dengan menambahkan fitur pencarian (searching) dan penghapusan data (deleting) pada struktur Doubly Linked List. Program ini tetap digunakan untuk menyimpan dan mengelola daftar makanan yang memiliki atribut nama, jenis, harga, dan rating.

File ListMakanan.h berisi rancangan struktur data serta deklarasi fungsi-fungsi baru seperti findByName, findByJenis, findByMinRating, dan beberapa fungsi penghapusan data seperti deleteFirst, deleteLast, deleteAfter, deleteBefore, serta deleteByName.
File ListMakanan.cpp berisi implementasi fungsi-fungsi tersebut. Fungsi searching digunakan untuk mencari data makanan berdasarkan nama, jenis, atau nilai rating minimal, sedangkan fungsi deleting digunakan untuk menghapus data dari posisi tertentu atau berdasarkan nama yang dicari.

Pada main.cpp, program membuat list makanan, menambahkan beberapa data ke dalamnya, lalu menampilkan hasilnya. Setelah itu, program menguji fitur pencarian dengan mencari data tertentu, kemudian melakukan beberapa penghapusan data seperti menghapus node pertama, sebelum node tertentu, atau berdasarkan nama makanan.

Hasil output program menampilkan daftar makanan sebelum dan sesudah dilakukan proses update, pencarian, dan penghapusan. Pengguna dapat melihat bagaimana data dalam list berubah secara dinamis setelah setiap operasi dilakukan.
Secara keseluruhan, Guided 2 ini bertujuan untuk memperdalam pemahaman tentang pengelolaan data dalam Doubly Linked List, khususnya pada proses pencarian dan penghapusan node secara efisien.

## Unguided 

### 1. Soal Unguided 1-3
![Screenshot Soal 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan6_Modul6/soal1_modul6.png)
![Screenshot Soal 2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan6_Modul6/soal2_modul6.png)
![Screenshot Soal 3](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan6_Modul6/soal3_modul6.png)

```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL
#include <iostream>
#include <string>
using namespace std;

struct kenderaan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kenderaan infotype;

typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

address findElm(List L, infotype x);

bool findNopol(List L, string nopol);

address findElmByNopol(List L, string nopol);
void deleteDataByNopol(List &L, string nopol);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif
```
```c++
#include "Doublylist.h"

void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmtList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
        P->prev = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
}

void insertLast(List &L, address P) {
    if (L.First == Nil) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "DATA LIST KOSONG" << endl;
        return;
    }

    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        
        if (P != L.First) {
            cout << endl;
        }
        
        P = P->prev;
    }
}

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

bool findNopol(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

address findElmByNopol(List L, string nopol) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = P->next;
        L.First->prev = Nil;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    if (L.First == L.Last) {
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = P->prev;
        L.Last->next = Nil;
        P->prev = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next->prev = Prec;
    P->next = Nil;
    P->prev = Nil;
}

void deleteDataByNopol(List &L, string nopol) {
    address Pdel = Nil;
    address P_target = findElmByNopol(L, nopol);

    if (P_target == Nil) {
        cout << "Data dengan nomor polisi " << nopol << " tidak ditemukan." << endl;
        return;
    }

    if (P_target == L.First) {
        deleteFirst(L, Pdel);
    } else if (P_target == L.Last) {
        deleteLast(L, Pdel);
    } else {
        address Prec = P_target->prev;
        deleteAfter(Prec, Pdel);
    }

    cout << "Data dengan nomor polisi " << nopol << " berhasil dihapus." << endl;
    dealokasi(Pdel);
}
```
```c++
#include "Doublylist.h"
#include <string>

int main() {
    List L;
    CreateList(L);
    
    infotype data;
    address P;

    // ======================================================
    // BAGIAN SOAL 1: MEMASUKKAN DATA
    // ======================================================

    // --- Input 1 (D001) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore(); 
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;

    // --- Input 2 (D003) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore();
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;

    // --- Input 3 (D001 - Duplikat) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore();
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;

    // --- Input 4 (D004) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore();
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;
    
    // --- Menampilkan Hasil Soal 1 ---
    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;
    
    // ======================================================
    // BAGIAN SOAL 2: MENCARI DATA
    // ======================================================
    
    infotype dataCari;
    address hasilCari;
    
    cout << "Masukkan Nomor Polisi yang dicari : ";
    getline(cin, dataCari.nopol);
    
    hasilCari = findElm(L, dataCari);
    
    if (hasilCari != Nil) {
        cout << endl;
        cout << "Nomor Polisi : " << hasilCari->info.nopol << endl;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Nomor polisi " << dataCari.nopol << " tidak ditemukan." << endl;
    }

    // ======================================================
    // BAGIAN SOAL 3: MENGHAPUS DATA
    // ======================================================
    
    string nopolHapus;
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    getline(cin, nopolHapus);
    
    deleteDataByNopol(L, nopolHapus);
    
    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);
    
    return 0;
}
```
```
### Output Soal1:

masukkan nomor polisi: D001
masukkan warna kendaraan: hitam
masukkan tahun kendaraan: 90

masukkan nomor polisi: D003
masukkan warna kendaraan: putih
masukkan tahun kendaraan: 70

masukkan nomor polisi: D001
masukkan warna kendaraan: merah
masukkan tahun kendaraan: 80
nomor polisi sudah terdaftar

masukkan nomor polisi: D004
masukkan warna kendaraan: kuning
masukkan tahun kendaraan: 90

DATA LIST 1
no polisi : D004
warna     : kuning
tahun     : 90

no polisi : D003
warna     : putih
tahun     : 70

no polisi : D001
warna     : hitam
tahun     : 90

```
```
### Output Soal2:
Masukkan Nomor Polisi yang dicari : D001

Nomor Polisi : D001
Warna        : hitam
Tahun        : 90
```
```
### Output Soal3:
Masukkan Nomor Polisi yang akan dihapus : D003
Data dengan nomor polisi D003 berhasil dihapus.

DATA LIST 1
no polisi : D004
warna     : kuning
tahun     : 90

no polisi : D001
warna     : hitam
tahun     : 90
```
```
##### Output 1
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan6_Modul6/modul6-output1.png)
```
```
### Output 2
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan6_Modul6/modul6_output2.png)
```
```
### Output 3
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan6_Modul6/modul6_output3.png)
```

Penjelasan Soal 1: Pembuatan ADT dan Insert Data

Bagian pertama program berfokus pada pembuatan ADT Doublylist dan implementasi prosedur dasarnya. Ini dicapai dengan mengimplementasikan prosedur CreateList, alokasi, dealokasi, printInfo, dan insertLast di dalam file Doublylist.cpp.

Di dalam main.cpp, setelah list awal L dibuat (menggunakan CreateList), program mensimulasikan empat kali input pengguna untuk data kendaraan. Program juga menyertakan logika untuk mencegah data duplikat berdasarkan nomor polisi, menggunakan fungsi helper findNopol.

Ketika data "D001" dimasukkan untuk kedua kalinya, program akan mendeteksi duplikasi dan menampilkan pesan "nomor polisi sudah terdaftar". Data yang berhasil dimasukkan adalah D001, D003, dan D004. Karena semua data dimasukkan menggunakan insertLast, urutan list akhirnya adalah D001 - D003 - D004. List ini kemudian dicetak menggunakan printInfo (secara terbalik dari Last ke First) dan digunakan untuk soal berikutnya.

Penjelasan Soal 2: Searching Data

Bagian kedua adalah implementasi fungsionalitas pencarian pada list yang sudah terbentuk (D001 - D003 - D004). Sebuah fungsi baru ditambahkan ke ADT: findElm(L : List, x : infotype) : address.

Fungsi findElm menelusuri list dari First ke Last (penelusuran maju) untuk menemukan elemen dengan nomor polisi yang sama dengan x.nopol. Di dalam main.cpp, program meminta pengguna "Masukkan Nomor Polisi yang dicari".

Jika pengguna memasukkan "D001", fungsi akan berhasil menemukan elemen dan mengembalikan address-nya. Program main kemudian menggunakan address tersebut untuk mencetak detail lengkap kendaraan (Nomor Polisi: D001, Warna: hitam, Tahun: 90). Jika pengguna memasukkan "D005", fungsi akan mengembalikan Nil dan program akan menampilkan pesan bahwa data tidak ditemukan.

Penjelasan Soal 3: Delete Data

Bagian terakhir dari program adalah operasi penghapusan elemen. Ini dicapai dengan mengimplementasikan tiga prosedur yang diminta di Doublylist.cpp: deleteFirst, deleteLast, dan deleteAfter.

Di dalam main.cpp, program meminta pengguna "Masukkan Nomor Polisi yang akan dihapus". Sesuai output yang diharapkan, pengguna memasukkan "D003". Logika program kemudian memanggil prosedur deleteDataByNopol (sebuah prosedur helper) yang pertama-tama mencari address dari "D003".

Karena "D003" berada di tengah list (setelah "D001" dan sebelum "D004"), prosedur internal deleteAfter akan dipanggil pada node "D001" (sebagai Prec) untuk menghapus node "D003". Setelah elemen Pdel berhasil dihapus, memori di-dealokasi.

Terakhir, main.cpp memanggil printInfo(L) sekali lagi. List yang awalnya berisi D001 - D003 - D004 kini berubah menjadi D001 - D004, dan dicetak secara mundur (D004 lalu D001) sesuai dengan output di soal.


## Kesimpulan
Kesimpulan dari latihan unguided ini adalah agar mahasiswa lebih terbiasa dengan implementasi double linked list.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

