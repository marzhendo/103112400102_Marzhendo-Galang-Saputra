# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Queue atau antrian adalah struktur data linier yang bekerja menggunakan prinsip FIFO (First In First Out), yaitu elemen yang pertama kali masuk akan menjadi elemen pertama yang keluar. Struktur ini meniru antrian dalam kehidupan nyata seperti antrian teller bank atau antrian pembelian tiket, di mana penambahan elemen selalu dilakukan di bagian belakang (rear), dan penghapusan dilakukan di bagian depan (front). [36]

Queue digunakan dalam berbagai aplikasi seperti sistem antrian layanan, penjadwalan proses pada sistem operasi, buffer data, serta algoritma pencarian seperti Breadth-First Search (BFS). Representasi queue yang umum adalah menggunakan array dengan dua penanda, yaitu Head untuk posisi elemen pertama dan Tail untuk posisi elemen terakhir. [36]


Operasi dasar pada queue terdiri dari Create(), IsEmpty(), IsFull(), Enqueue(), dan Dequeue(). Create() digunakan untuk membuat queue kosong, IsEmpty() mengecek apakah antrian kosong, IsFull() mengecek apakah antrian penuh, Enqueue() menambahkan elemen ke bagian belakang antrian, dan Dequeue() menghapus elemen dari bagian depan antrian. [37]

Pada implementasinya, queue dinyatakan kosong jika Head dan Tail bernilai -1. Penambahan elemen dilakukan dengan menaikkan nilai Tail terlebih dahulu sebelum data dimasukkan, sedangkan penghapusan elemen pada Dequeue() dilakukan dengan menghapus elemen pada posisi Head dan menggeser seluruh elemen ke depan untuk menutup posisi yang kosong. [38]

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

```queue.h
#ifndef QUEUE_H
#define QUEUE_H
#define NIL NULL
using namespace std;
#include <string>

struct Node {
    std::string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue& Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue& Q, const string& nama);
void deQueue(queue& Q);
void viewQueue(queue Q);
void clearQueue(queue& Q);

#endif


```
```queue.cpp
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "Nama " << nama << " berhasil ditambahkan ke dalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}



```
```main.cpp
#include "queue.h"
#include <iostream>
int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    cout << endl;
    return 0;
}
```
Program guided 1 ini bertujuan untuk mengimplementasikan struktur data Queue (Antrian) menggunakan Linked List dalam bahasa C++.
Setiap node dalam queue memiliki data berupa string (nama) dan pointer next yang menunjuk ke node berikutnya.

File queue.h berisi rancangan struktur data dan deklarasi fungsi-fungsi yang digunakan, seperti membuat queue, mengecek apakah queue kosong atau penuh, menambah data ke belakang queue (enQueue), menghapus data dari depan queue (deQueue), menampilkan isi queue, serta menghapus semua data dalam queue.

File queue.cpp berisi implementasi dari fungsi-fungsi tersebut. Di dalamnya terdapat logika untuk menambahkan elemen ke antrian, menghapus elemen dari antrian, menampilkan seluruh isi antrian, dan mengosongkan antrian. Setiap operasi enQueue dan deQueue disertai dengan pesan konfirmasi untuk memudahkan pelacakan.

File main.cpp adalah bagian utama yang menjalankan program. Di sini, queue dibuat dan diisi dengan beberapa nama menggunakan operasi enQueue. Setelah itu, isi queue ditampilkan. Kemudian dilakukan operasi deQueue sebanyak empat kali untuk menghapus elemen dari depan antrian, dan isi queue kembali ditampilkan. Terakhir, seluruh isi queue dihapus menggunakan clearQueue.

Hasil output program menampilkan konfirmasi setiap operasi enQueue dan deQueue yang dilakukan, serta isi queue sebelum dan sesudah dilakukan proses penghapusan data.

Secara sederhana, program ini membantu memahami cara menambah, menampilkan, menghapus, dan mengosongkan data pada struktur linked list dengan prinsip FIFO (First In First Out), di mana elemen pertama yang masuk adalah yang pertama keluar.



### 2. Guided 2

```queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enqueue(queue &Q, string nama);
void dequeue(queue &Q);
void viewQueue(queue Q);

#endif

```
```queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }


```
```main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}


```
Program guided 2 ini bertujuan untuk mengimplementasikan struktur data Queue (Antrian) menggunakan Array Statis dalam bahasa C++.
Queue diimplementasikan dengan array berkapasitas tetap sebesar 5 elemen, dan setiap elemen menyimpan data berupa string (nama).

File queue.h berisi definisi struktur data queue yang terdiri dari array string untuk menyimpan nama, serta variabel head dan tail untuk menandai posisi elemen pertama dan terakhir dalam antrian. File ini juga mendeklarasikan fungsi-fungsi operasi queue seperti pengecekan kondisi penuh/kosong, pembuatan queue, penambahan data (enqueue), penghapusan data (dequeue), dan penampilan isi queue.

File queue.cpp berisi implementasi dari fungsi-fungsi tersebut dengan beberapa alternatif implementasi yang dicatat dalam komentar:

Implementasi 1: Head diam, tail bergerak (Queue Linear Statis)

Implementasi 2: Head dan tail bergerak (Queue Linear Dinamis)

Implementasi 3: Head dan tail berputar (Queue Circular)

Pada kode yang aktif digunakan, diimplementasikan pendekatan pertama dimana head tetap pada posisi awal dan elemen digeser ke depan setiap kali dilakukan dequeue. Setiap operasi enqueue dan dequeue disertai dengan pesan konfirmasi untuk memudahkan pelacakan proses.

File main.cpp adalah bagian utama yang menjalankan program. Di sini, queue dibuat dan diisi dengan enam nama menggunakan operasi enqueue (meskipun kapasitas maksimal hanya 5). Setelah itu, isi queue ditampilkan. Kemudian dilakukan operasi dequeue sebanyak empat kali untuk menghapus elemen dari depan antrian, dan isi queue kembali ditampilkan untuk melihat perubahan.

Hasil output program menampilkan konfirmasi setiap operasi enqueue yang berhasil, pesan error ketika queue penuh, isi queue sebelum dan sesudah dilakukan proses dequeue, serta urutan nomor untuk setiap elemen dalam antrian.

Secara sederhana, program ini membantu memahami cara mengelola antrian dengan array statis menggunakan prinsip FIFO (First In First Out), dimana elemen pertama yang masuk adalah yang pertama keluar, serta menampilkan berbagai teknik implementasi queue yang mungkin digunakan.


## Unguided 

### 1. Soal Unguided 1-3
![Screenshot Soal 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal1.png)
![Screenshot Soal 2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal2.png)
![Screenshot Soal 3](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal3.png)

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iomanip> 

using namespace std;

const int MAX_QUEUE = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
```c++
#include "stack.h"

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX_STACK - 1;
}

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    if (!isEmpty(S)) {
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (isEmpty(S)) {
        return;
    }

    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    while (!isEmpty(S)) {
        push(temp1, pop(S));
    }
    while (!isEmpty(temp1)) {
        push(temp2, pop(temp1));
    }
    while (!isEmpty(temp2)) {
        push(S, pop(temp2));
    }
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char c;
    c = cin.get();
    while (c != '\n') {
        if (c >= '0' && c <= '9') {
            infotype x = c - '0';
            push(S, x);
        }
        c = cin.get();
    }
}
```
```C++
//soal1
#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.tail == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            CreateQueue(Q);
        } else {
            for (int i = Q.head; i < Q.tail; i++) {
                Q.info[i] = Q.info[i+1];
            }
            Q.tail--;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << setw(3) << Q.head << setw(3) << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
```C++
//soal2
#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    return Q.head == 0 && Q.tail == MAX_QUEUE - 1;
}

void enqueue(Queue &Q, infotype x) {
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    } else if (Q.tail == MAX_QUEUE - 1) {
        if (Q.head != 0) {
            int i = Q.head;
            int j = 0;
            while (i <= Q.tail) {
                Q.info[j] = Q.info[i];
                i++;
                j++;
            }
            Q.head = 0;
            Q.tail = j;
            Q.info[Q.tail] = x;
        }
    } else {
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            CreateQueue(Q);
        } else {
            Q.head++;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << setw(3) << Q.head << setw(3) << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}
```
```C++
//soal3
#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    if (isEmptyQueue(Q)) {
        return false;
    }
    int next_tail = (Q.tail + 1) % MAX_QUEUE;
    return next_tail == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX_QUEUE;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            CreateQueue(Q);
        } else {
            Q.head = (Q.head + 1) % MAX_QUEUE;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << setw(3) << Q.head << setw(3) << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        if (Q.head <= Q.tail) {
            for (int i = Q.head; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        } else {
            for (int i = Q.head; i < MAX_QUEUE; i++) {
                cout << Q.info[i] << " ";
            }
            for (int i = 0; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        }
    }
    cout << endl;
}
```

```C++
//main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    
    cout<<"-------------------"<<endl;
    cout<<" H  T | Queue info"<<endl;
    cout<<"-------------------"<<endl;

    createQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q);

    enqueue(Q, 4); 
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q);
    
    return 0;
}
```
### Output Soal1:

-------------------
 H  T | Queue info
-------------------
 -1 -1 | empty queue
  0  0 | 5
  0  1 | 5 2
  0  2 | 5 2 7
  0  1 | 2 7
  0  0 | 7
  0  1 | 7 4
  0  0 | 4
 -1 -1 | empty queue



### Output Soal2:
Hello world!
-------------------
 H  T | Queue info
-------------------
 -1 -1 | empty queue
== Mengisi Penuh Queue ==
  0  4 | 1 2 3 4 5
== Dequeue 2x (Menciptakan 'Penuh') ==
  2  4 | 3 4 5
== Enqueue 2x (Memicu Perbedaan Logika) ==
  0  3 | 3 4 5 6
  0  4 | 3 4 5 6 7
== Mengosongkan Queue ==
  1  4 | 4 5 6 7
  2  4 | 5 6 7
  3  4 | 6 7
  4  4 | 7
 -1 -1 | empty queue


### Output Soal3:
-------------------
 H  T | Queue info
-------------------
 -1 -1 | empty queue
== Mengisi Penuh Queue ==
  0  4 | 1 2 3 4 5
== Dequeue 2x (Menciptakan 'Penuh Sementara) ==
  2  4 | 3 4 5
== Enqueue 2x (Memicu Perbedaan Logika) ==
  2  0 | 3 4 5 6
  2  1 | 3 4 5 6 7
== Mengosongkan Queue ==
  3  1 | 4 5 6 7
  4  1 | 5 6 7
  0  1 | 6 7
  1  1 | 7
 -1 -1 | empty queue


##### Output 1
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Output%20Final.png)

### Output 2
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Output%20Final.png)

### Output 3
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Output%20Final.png)

Tentu, berikut adalah deskripsi penjelasan untuk ketiga kode soal stack tersebut, yang ditulis sesuai dengan gaya contoh yang Anda berikan.

Penjelasan Soal 1: ADT Stack Array dan Operasi Dasar

Bagian pertama program berfokus pada implementasi ADT Stack menggunakan representasi Array. Ini dicapai dengan mendefinisikan Type Stack (terdiri dari array info[20] dan integer top) di file stack.h, serta mengimplementasikan prosedur dasarnya (createStack, push, pop, printInfo, balikStack) di file stack.cpp.

Di dalam main.cpp, setelah stack S dibuat (menggunakan createStack), program melakukan serangkaian operasi push dan pop untuk memanipulasi data. Program mem-push 3, 4, dan 8. Kemudian mem-pop (menghapus 8). Mem-push 2 dan 3. Kemudian mem-pop (menghapus 3). Terakhir mem-push 9.

Setelah semua operasi, stack akhir yang terbentuk adalah [TOP] 9 2 4 3. Stack ini kemudian dicetak oleh printInfo, dilanjutkan dengan pemanggilan balikStack. Prosedur balikStack (menggunakan dua stack temporer) membalik urutan stack menjadi [TOP] 3 4 2 9, yang kemudian dicetak lagi.

Penjelasan Soal 2: Push Ascending

Bagian kedua adalah implementasi fungsionalitas pushAscending yang ditambahkan ke stack.cpp. Prosedur ini dirancang untuk memasukkan elemen baru (x) ke dalam stack sedemikian rupa sehingga stack tetap terurut (dalam kasus ini, terurut ascending dari top ke bottom, atau nilai terkecil di top).

Logika pushAscending bekerja dengan mem-pop sementara semua elemen di S yang nilainya lebih kecil dari x ke stack temporer. Kemudian, x di-push ke S, dan elemen dari stack temporer dikembalikan ke S.

Di dalam main.cpp, program memanggil pushAscending secara berurutan dengan data 3, 4, 8, 2, 3, dan 9. Setelah semua pemanggilan, stack akhir yang terbentuk adalah [TOP] 2 3 3 4 8 9. Stack ini kemudian dicetak oleh printInfo, dilanjutkan dengan pemanggilan balikStack yang membalik urutan menjadi [TOP] 9 8 4 3 3 2, yang kemudian dicetak lagi.

Penjelasan Soal 3: Input Stream

Bagian terakhir adalah implementasi prosedur getInputStream di stack.cpp. Prosedur ini bertugas membaca input karakter dari pengguna secara kontinu menggunakan cin.get() hingga pengguna menekan tombol Enter (karakter \n).

Selama membaca, prosedur ini memfilter input: jika karakter adalah digit ('0' sampai '9'), karakter tersebut dikonversi menjadi integer dan di-push ke dalam stack S. Karakter lain (selain \n) akan diabaikan.

Di dalam main.cpp, program memanggil getInputStream. Pengguna memasukkan string "4729601". Karena push adalah operasi LIFO (Last In First Out), stack S akan berisi data dengan urutan [TOP] 1 0 6 9 2 7 4. Stack ini kemudian dicetak oleh printInfo. Terakhir, balikStack dipanggil untuk membalik urutan stack menjadi [TOP] 4 7 2 9 6 0 1, yang dicetak untuk kedua kalinya.

## Kesimpulan
Kesimpulan dari latihan unguided ini adalah agar mahasiswa lebih terbiasa dengan implementasi stack.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

