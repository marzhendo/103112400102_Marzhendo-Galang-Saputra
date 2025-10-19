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

## list.h
```list.h
#ifndef LIST_H
#define LIST_H
#define Nill NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer
    dataMahasiswa isiData;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printlist(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif

```
##list.cpp
```list.cpp
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

```
##main.cpp
```main.cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nill;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printlist(List);
    return 0;
}
```
Program Guided 1 ini adalah implementasi dari konsep Abstract Data Type (ADT) dalam bahasa C++ yang digunakan untuk mengatur data mata pelajaran secara sistematis. Struktur ADT dibagi ke dalam tiga berkas: pelajaran.h, yang berfungsi sebagai deklarasi struktur data dan prototipe fungsi; pelajaran.cpp, yang memuat detail implementasi dari fungsi-fungsi tersebut; serta main.cpp, yang menjadi bagian utama program. Secara keseluruhan, program utama memanfaatkan ADT ini untuk membuat data pelajaran bernama "Struktur Data" melalui pemanggilan fungsi create_pelajaran, lalu menampilkannya dengan fungsi tampil_pelajaran.

### 2. Guided 2

## list.h
```list.h
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer
    dataMahasiswa isiData;
    address next;
};

struct linkedlist {
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printlist(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif


```
## list.cpp
```list.cpp
#include <iostream>
#include "list.h"
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
}

address alokasi(string nama, string nim, int umur) {
    address nodeBaru = new node;
    nodeBaru -> isiData.nama = nama;
    nodeBaru -> isiData.nim = nim;
    nodeBaru -> isiData.umur = umur;
    nodeBaru -> next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node -> next = Nil;
    delete node;
}

// prosedur untuk insert
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru -> next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
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
        while (nodeBantu -> next != Nil) {
            nodeBantu = nodeBantu -> next;
        }
        nodeBantu -> next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
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
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}


//prosedur untuk menampilkan isi list
void printlist(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu -> isiData.nama << ", NIM : " << nodeBantu -> isiData.nim << ", Usia : "
            << nodeBantu -> isiData.umur << endl;
            nodeBantu = nodeBantu -> next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

```
## main.cpp
```main.cpp
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printlist(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printlist(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printlist(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program Guided 2 ini menunjukkan cara penggunaan konsep ADT di C++ untuk mengatur data mata pelajaran dengan rapi. ADT-nya terbagi menjadi tiga file: pelajaran.h untuk mendefinisikan struktur dan fungsi, pelajaran.cpp untuk menulis logika kerjanya, serta main.cpp sebagai program utama. Program utama menggunakan ADT tersebut untuk membuat data pelajaran “Struktur Data” lewat fungsi create_pelajaran dan menampilkannya menggunakan tampil_pelajaran.

## Unguided 

### 1. Soal Unguided 1


![https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan4_Modul4/soal1_modul4.1.png]
![https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan4_Modul4/soal1_modul4.2.png]
![https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan4_Modul4/soal1_modul4.3.png]

## Singlylist.h
```Singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

```
## Singlylist.cpp
```Singlylist.cpp
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

```
## main.cpp
```main.cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :
```
9 12 8 0 2
```

##### Output 1
![https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan4_Modul4/output_soal1_modul4.png]


Program Unguided 1 ini adalah mendemonstrasikan operasi dasar insertion (pemasukan) dan deletion (penghapusan) pada sebuah Single Linked List. Awalnya, di Soal 1, sebuah list kosong L dibuat. Kemudian, program mengalokasikan lima node (P1 hingga P5) dengan nilai 2, 0, 8, 12, dan 9. Semua node ini dimasukkan ke dalam list menggunakan fungsi insertFirst, yang menyebabkan setiap node baru "menyelak" ke posisi paling depan. Hasilnya, urutan list menjadi terbalik dari urutan pemasukan, yaitu 
```
9 -> 12 -> 8 -> 0 -> 2.
```

### 2. Soal Unguided 2

```
![https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan4_Modul4/soal2_modul4.png]
```

## Singlylist.h
```Singlylist.h
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif


```
## Singlylist.cpp
```Singlylist.cpp
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
```
## main.cpp
```main.cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    deleteFirst(L, P5);
    dealokasi(P5);

    deleteLast(L, P1);
    dealokasi(P1);

    deleteAfter(L, P3, P4);
    dealokasi(P3);

    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
```
### Output Unguided 2 
9 12 8 0 2 
12 0 
Jumlah node : 2
- List Berhasil Terhapus -
Jumlah node : 0
```
##### Output Unguided 2 
![https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan4_Modul4/output_soal2_modul4.png]

Program Unguided 2 ini melakukan tiga operasi penghapusan pada list tersebut. Pertama, deleteFirst digunakan untuk menghapus node 9 (elemen pertama). Kedua, deleteLast menghapus node 2 (elemen terakhir). Ketiga, deleteAfter menghapus node 8, yang berada setelah node 12. Setelah tiga penghapusan ini, program mencetak isi list yang tersisa (12 0) dan jumlah nodenya (Jumlah node : 2). Terakhir, fungsi deleteList dipanggil untuk menghapus semua node yang tersisa di memori, dan program mengonfirmasi keberhasilannya dengan mencetak jumlah node akhir, yaitu 0.



## Kesimpulan
Kesimpulan dari latihan unguided ini adalah agar mahasiswa lebih terbiasa dengan single linked list

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

