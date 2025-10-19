# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Tipe Data Abstrak (ADT) dapat didefinisikan sebagai model matematika dari objek data yang menyempurnakan tipe data dengan cara mengaitkannya dengan fungsi-fungsi yang beroperasi pada data yang bersangkutan [57]. ADT adalah tipe data yang dibuat oleh pemrogram untuk kemudahan pemrograman serta untuk mengakomodasi tipe data yang tidak diakomodasi oleh bahasa pemrograman yang digunakan [63].

Tujuan utama dari ADT adalah untuk memisahkan struktur penyimpanan dari perilaku abstrak tipe data tersebut[65]. Hal ini memungkinkan ADT menjadi sarana pengembangan sistem yang bersifat modular, di mana pembuat dan pengguna hanya perlu menyepakati interface ADT tanpa perlu membahas detail implementasinya [70, 71].
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

Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array
dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI
dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
//header
#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
using namespace std;
struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

void inputMahasiswa(Mahasiswa &m);
void hitungNilaiAkhir(Mahasiswa &m);
void tampilMahasiswa(const Mahasiswa &m);

#endif

//implementasi
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMahasiswa(Mahasiswa &m) {
    cout << "Nama: ";
    getline(cin, m.nama);
    cout << "NIM: ";
    cin >> m.nim;
    cout << "UTS: ";
    cin >> m.uts;
    cout << "UAS: ";
    cin >> m.uas;
    cout << "Tugas: ";
    cin >> m.tugas;
    cin.ignore();
}

void hitungNilaiAkhir(Mahasiswa &m) {
    m.nilaiAkhir = (0.3 * m.uts) + (0.4 * m.uas) + (0.3 * m.tugas);
}

void tampilMahasiswa(const Mahasiswa &m) {
    cout << "Nama: " << m.nama << "\n";
    cout << "NIM: " << m.nim << "\n";
    cout << "Nilai Akhir: " << m.nilaiAkhir <<  "\n";
}

//driver
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    const int MAX_MAHASISWA = 10;
    Mahasiswa daftarMhs[MAX_MAHASISWA];
    int jumlahMhs = 0;
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlahMhs;
    cin.ignore();

    if (jumlahMhs > MAX_MAHASISWA) {
        jumlahMhs = MAX_MAHASISWA;
    }

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nInput Mahasiswa ke-" << i + 1 << ":\n";
        inputMahasiswa(daftarMhs[i]);
        hitungNilaiAkhir(daftarMhs[i]);
    }

    cout << "\nData Hasil Inputan\n";
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nData ke-" << i+1 << ":\n";
        tampilMahasiswa(daftarMhs[i]);
    }
}
```
### Output Unguided 1 :

Masukkan jumlah mahasiswa (max 10): 2

Input Mahasiswa ke-1:
Nama: Fajar
NIM: 1
UTS: 89
UAS: 88
Tugas: 100

Input Mahasiswa ke-2:
Nama: Aloy
NIM: 2
UTS: 55
UAS: 21
Tugas: 90

Data Hasil Inputan

Data ke-1:
Nama: Fajar
NIM: 1
Nilai Akhir: 91.9

Data ke-2:
Nama: Aloy
NIM: 2
Nilai Akhir: 51.9 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


Program Unguided 1 ini adalah contoh implementasi penggunaan struct dan array of struct untuk mengelola data mahasiswa. Pertama, program mendefinisikan sebuah struct bernama Mahasiswa yang berfungsi untuk menyimpan data individu, dari nama, nim, serta nilai uts, uas, dan tugas.

program dimulai di fungsi main(), di mana pengguna diminta untuk memasukkan jumlah mahasiswa yang akan diinput. Selanjutnya, program melakukan perulangan untuk setiap mahasiswa. Di dalam perulangan ini, prosedur inputMahasiswa() dipanggil untuk meminta pengguna memasukkan data detail setiap mahasiswa. Setelah data terisi, program langsung memanggil prosedur hitungNilaiAkhir() untuk mengkalkulasi nilai akhir berdasarkan bobot nilai yang telah ditentukan (30% UTS, 40% UAS, dan 30% Tugas), dan hasilnya disimpan kembali ke dalam struct.

Terakhir, setelah semua data mahasiswa berhasil diinput dan diolah, program akan menampilkan kembali seluruh data yang telah tersimpan secara terstruktur dengan memanggil prosedur tampilMahasiswa() untuk setiap mahasiswa, yang mencakup nama, NIM, dan nilai akhir yang sudah dihitung.

### 2. Soal Unguided 2

Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp"
Cobalah hasil implementasi ADT pada file "main.cpp"

```C++
//header
//header guard digunakan untuk mencegah file header yg sama 
// di-include lebih dari sekali dalam 1 program.
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

//deklarasi adt pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif

//implementasi

#include "pelajaran.h"

//Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) {
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Kode pelajaran : " << pel.kodeMapel << endl;
}

//driver
#include <iostream>
#include "pelajaran.h"

using namespace std;

int main() {
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran (namapel,kodepel);
tampil_pelajaran(pel);
return 0;
}
```
### Output Unguided 2 
Nama pelajaran : Struktur Data
Kode pelajaran : STD

##### Output Unguided 2 
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)



Program Unguided 2 ini merupakan contoh implementasi dasar dari Abstract Data Type (ADT) menggunakan struct dalam bahasa C++ yang dipisahkan ke dalam beberapa file. Tujuannya adalah untuk mendemonstrasikan konsep modularitas, di mana deklarasi, implementasi, dan program utama ditempatkan pada file yang berbeda.

Pertama, program mendefinisikan sebuah struct bernama pelajaran di dalam file header (pelajaran.h), yang berfungsi sebagai blueprint untuk menyimpan data mata pelajaran, yang terdiri dari namaMapel dan kodeMapel. File header ini juga mendeklarasikan sebuah function create_pelajaran() yang bertugas membuat objek dari struct tersebut dan sebuah prosedur tampil_pelajaran() untuk menampilkan isinya.

Implementasi dari function dan prosedur tersebut ditempatkan secara terpisah di dalam file pelajaran.cpp. Terakhir, alur utama program dijalankan dari fungsi main() pada file main.cpp. Di dalam main, program menginisialisasi data mata pelajaran ("Struktur Data" dan "STD") secara langsung di dalam kode. Data ini kemudian dilewatkan ke function create_pelajaran() untuk membuat sebuah objek pelajaran. Setelah objek berhasil dibuat, prosedur tampil_pelajaran() dipanggil untuk menampilkan data tersebut.

### 3. Soal Unguided 3
 Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
#include <iomanip>

using namespace std;

void tampilArray(const int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}

void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{99, 88, 77}, {66, 55, 44}, {33, 22, 11}};
    int nilaiX = 100;
    int nilaiY = 200;
    int *pointerX = &nilaiX;
    int *pointerY = &nilaiY;

    cout << "Array A Awal:" << endl;
    tampilArray(arrayA);
    cout << "\nArray B Awal:" << endl;
    tampilArray(arrayB);

    tukarElemenArray(arrayA, arrayB, 1, 1);

    cout << "\nArray A Setelah Tukar [1][1]:" << endl;
    tampilArray(arrayA);
    cout << "\nArray B Setelah Tukar [1][1]:" << endl;
    tampilArray(arrayB);

    cout << "\nNilai Awal -> X: " << *pointerX << ", Y: " << *pointerY << endl;
    tukarPointer(pointerX, pointerY);
    cout << "Nilai Akhir -> X: " << *pointerX << ", Y: " << *pointerY << endl;

}
```
### Output Unguided 3 :
Array A Awal:
   1   2   3
   4   5   6
   7   8   9

Array B Awal:
  99  88  77
  66  55  44
  33  22  11

Array A Setelah Tukar [1][1]:
   1   2   3
   4  55   6
   7   8   9

Array B Setelah Tukar [1][1]:
  99  88  77
  66   5  44
  33  22  11

Nilai Awal -> X: 100, Y: 200
Nilai Akhir -> X: 200, Y: 100
##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)


Program Unguided 3 ini dibuat untuk menunjukkan dua cara berbeda dalam menukar nilai antar variabel menggunakan fungsi, yaitu dengan menukar elemen array secara langsung dan dengan menukar nilai melalui pointer (penunjuk alamat memori).

program pertama-tama menyiapkan dua buah array dua dimensi, yaitu arrayA dan arrayB, beserta dua variabel biasa, nilaiX dan nilaiY. Program juga membuat dua pointer, yaitu pointerX yang menunjuk ke alamat nilaiX, dan pointerY yang menunjuk ke alamat nilaiY.

Selanjutnya, program menjalankan dua skenario penukaran. Skenario pertama adalah menukar satu elemen spesifik (yaitu elemen di posisi [1][1]) antara arrayA dan arrayB dengan memanggil fungsi tukarElemenArray(). Program akan menampilkan kondisi kedua array sebelum dan sesudah penukaran untuk menunjukkan perubahannya.

Pada skenario kedua, program mendemonstrasikan penukaran nilai dengan pointer. Program akan menampilkan nilai awal dari nilaiX dan nilaiY. Kemudian, fungsi tukarPointer() dipanggil dengan memberikan alamat dari kedua variabel tersebut. Fungsi ini akan menukar isi dari nilaiX dan nilaiY secara tidak langsung melalui alamatnya. Terakhir, program menampilkan kembali nilai akhir dari kedua variabel untuk membuktikan bahwa nilainya telah berhasil ditukar.

## Kesimpulan
Kesimpulan dari latihan unguided ini adalah agar mahasiswa lebih terbiasa dengan abstract data type dan penggunaan array, pointer, serta reference

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

