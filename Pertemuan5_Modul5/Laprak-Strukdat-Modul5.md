# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Single Linked List merupakan salah satu bentuk struktur data dinamis yang terdiri dari rangkaian simpul (node) yang saling terhubung secara sekuensial melalui pointer atau referensi. Setiap simpul pada Single Linked List terdiri atas dua bagian, yaitu bagian data yang menyimpan informasi dan bagian pointer yang menunjuk ke simpul berikutnya dalam daftar. Hubungan satu arah antar simpul inilah yang membedakan Single Linked List dengan jenis list lain seperti Double Linked List atau Circular Linked List [40].

Struktur Single Linked List memungkinkan penyimpanan dan pengelolaan data secara dinamis karena ukuran list tidak harus ditentukan di awal program. Penambahan dan penghapusan elemen dapat dilakukan dengan efisien tanpa perlu menggeser data seperti pada array. Hal ini menjadikan Single Linked List sangat berguna untuk aplikasi yang memerlukan manipulasi data secara fleksibel dan sering mengalami perubahan ukuran [41].

Tujuan utama dari penggunaan Single Linked List adalah untuk mempermudah pengelolaan data yang bersifat dinamis dengan efisiensi memori yang lebih baik. Dengan menggunakan pointer, setiap node dapat dialokasikan dan dihapus secara independen selama program berjalan (runtime). Selain itu, struktur ini juga membantu memahami konsep dasar hubungan antar objek dalam memori menggunakan pointer, yang merupakan dasar dari banyak struktur data lanjutan seperti stack, queue, dan tree [42].
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
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif

```
```listBuah.cpp
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}


```
```main.cpp
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    // delFirst(List);
    // delLast(List);
    // delAfter(List, nodeD, nodeC);

    // cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    // printList(List);
    // cout << "jumlah node : " << nbList(List) << endl;
    // cout << endl;

    // deleteList(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    // printList(List);
    // cout << "jumlah node : " << nbList(List) << endl;
    // cout << endl;

    return 0;
}
```
Program Guided 1 ini adalah implementasi dari konsep Abstract Data Type (ADT) dalam bahasa C++ yang digunakan untuk mengatur data mata pelajaran secara sistematis.

Struktur ADT dibagi ke dalam tiga berkas: listBuah.h, yang berfungsi sebagai deklarasi struktur data dan prototipe fungsi untuk Linked List; listBuah.cpp, yang memuat detail implementasi dari fungsi-fungsi tersebut; serta main.cpp, yang menjadi bagian utama program.

Secara keseluruhan, program utama memanfaatkan ADT ini untuk membuat data buah bernama "linkedlist List" melalui pemanggilan fungsi createList, melakukan operasi insert (insertFirst, insertLast, insertAfter), melakukan operasi update (updateFirst, updateLast, updateAfter), dan melakukan operasi searching (FindNodeByData, FindNodeByAddress, FindNodeByRange), lalu menampilkannya dengan fungsi printList dan menghitung jumlah nodenya dengan nbList.


## Unguided 

### 1. Soal Unguided 1-3
![Screenshot Soal 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal1.png)
![Screenshot Soal 2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal2.png)
![Screenshot Soal 3](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal3.png)

```C++
//ListAngka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka Angka;
    address Next;
};

struct linkedList {
    address First;
};

bool isEmpty(linkedList L);
void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
int nbList(linkedList L);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);

void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

void SearchByData(linkedList L, dataAngka data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, dataAngka nilaiMin);

#endif
```

```ListAngka.cpp
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
```
```main.cpp
//driver
#include "listAngka.h"
#include <iostream>

using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;
    CreateList(List);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    delAfter(List, nodeB, nodeC);

    printList(List);
    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    printList(List);
    cout << endl;

    SearchByData(List, 20);
    SearchByData(List, 55);
    SearchByAddress(List, nodeB);
    SearchByAddress(List, nodeA);
    SearchByRange(List, 40);
    cout << endl;

   int sum = 0;
    int subtraction = 0; 
    long long multiplication = 1;
    bool firstNode = true;
    address nodeBantu = List.First;

    while (nodeBantu != Nil) {
        sum += nodeBantu->Angka;
        multiplication *= nodeBantu->Angka;

        if (firstNode) {
            
            firstNode = false;
        } else {
            
            subtraction -= nodeBantu->Angka;
        }
        nodeBantu = nodeBantu->Next;
    }

    cout << "Total penjumlahan : " << sum << endl;
    cout << "Total pengurangan : " << subtraction << endl;
    cout << "Total perkalian : " << multiplication << endl;
    cout << endl;


    return 0;
}
```
```
### Output Unguided  :
```
40 - 18 - 25 - 8 - 33 - 

Masukkan update data node pertama : 50
Data Berhasil Diupdate!

masukkan update data node setelah 25 : 29
Data Berhasil Diupdate!

masukkan update data node terakhir : 45
Data Berhasil Diupdate!

masukkan update data node setelah 50 : 20
Data Berhasil Diupdate!

50 - 20 - 25 - 29 - 45 -

Data 20 ditemukan pada posisi ke-2!

Node dengan data 55 tidak ditemukan!

Node dengan alamat 0x1b347073910 tidak ditemukan dalam list!

Node ditemukan pada posisi ke-4!
Alamat node : 0x1b347073a10
Nilai : 29

--- Data diatas nilai 40 ---
Data ditemukan pada posisi ke-1, nilai : 50
Data ditemukan pada posisi ke-5, nilai : 45


Total penjumlahan : 169
Total pengurangan : -119
Total perkalian : 32625000

```

##### Output 1
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Output%20Final.png)


Penjelasan Soal 1: Update Data
Bagian pertama program berfokus pada manipulasi data yang sudah ada di dalam linked list. Ini dicapai dengan mengimplementasikan tiga prosedur baru di listAngka.cpp: updateFirst, updateLast, dan updateAfter. Prosedur-prosedur ini memungkinkan pengguna untuk mengganti nilai pada node tertentu.

Di dalam main.cpp, setelah list awal (40 - 18 - 25 - 8 - 33 -) selesai dibentuk, program memanggil serangkaian fungsi update ini. updateFirst(List) dipanggil untuk mengubah data 40 menjadi 50 (sesuai input pengguna), updateAfter(List, nodeD) dipanggil untuk mengubah data setelah nodeD (yaitu 8) menjadi 29, dan seterusnya. Setelah semua operasi update selesai, list tersebut berubah menjadi 50 - 20 - 25 - 29 - 45 -, yang kemudian digunakan untuk soal berikutnya.

Penjelasan Soal 2: Searching Data
Bagian kedua adalah implementasi fungsionalitas pencarian pada list yang sudah di-update (50 - 20 - 25 - 29 - 45 -). Tiga prosedur baru ditambahkan ke ADT: SearchByData, SearchByAddress, dan SearchByRange.

Prosedur SearchByData menelusuri list untuk menemukan data dengan nilai yang sama persis (misal, menemukan 20 tapi tidak menemukan 55). SearchByAddress menelusuri list untuk mencari node dengan alamat memori yang spesifik; ini ditunjukkan saat program berhasil menemukan nodeA (yang berisi nilai 29) tetapi gagal menemukan nodeB (karena nodeB telah dihapus pada tahap setup awal). Terakhir, SearchByRange mencari dan menampilkan semua data yang nilainya sama dengan atau lebih besar dari batas minimal yang ditentukan (misalnya, data 50 dan 45 untuk nilaiMin 40).

Penjelasan Soal 3: Operasi Aritmetika
Bagian terakhir dari program adalah operasi aritmetika yang dilakukan pada list hasil update (50 - 20 - 25 - 29 - 45 -). Logika ini diimplementasikan langsung di dalam fungsi main(), bukan sebagai bagian dari ADT di .cpp. Program melakukan satu kali traversal (penelusuran) pada list untuk menghitung tiga nilai:

Total penjumlahan: Variabel sum diinisialisasi ke 0 dan semua nilai elemen ditambahkan (0 + 50 + 20 + 25 + 29 + 45), menghasilkan 169.

Total pengurangan: Sesuai dengan output yang diharapkan soal, variabel subtraction diinisialisasi ke 0. Program kemudian mengabaikan node pertama dan mengurangkan semua nilai node berikutnya (0 - 20 - 25 - 29 - 45), menghasilkan -119.

Total perkalian: Variabel multiplication diinisialisasi ke 1 dan semua nilai elemen dikalikan satu sama lain (1 * 50 * 20 * 25 * 29 * 45), menghasilkan 32625000.


## Kesimpulan
Kesimpulan dari latihan unguided ini adalah agar mahasiswa lebih terbiasa dengan single linked list

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

