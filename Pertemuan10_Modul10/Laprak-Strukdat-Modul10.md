# <h1 align="center">Laporan Praktikum Modul 10 - Tree</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Tree dalam pemrograman merupakan struktur data non-linear yang digunakan terutama untuk merepresentasikan hubungan data yang bersifat hierarkis antar elemen-elemennya. Struktur ini terdiri dari kumpulan elemen di mana salah satu elemennya disebut dengan root (akar) dan sisa elemen lainnya disebut sebagai simpul (node atau vertex). Simpul-simpul ini kemudian terpecah menjadi sejumlah himpunan yang tidak saling berhubungan satu sama lain yang disebut dengan subtree atau cabang. [72]

Meskipun Tree memiliki keterkaitan dengan struktur data Graph, terdapat perbedaan spesifik di antara keduanya. Perbedaan utamanya adalah pada Tree tidak terdapat cycle (siklus/putaran), sedangkan pada Graph siklus dapat terjadi. Selain itu, Tree memiliki root yang terdefinisi secara jelas, berbeda dengan Graph yang tidak memiliki konsep root. [73]

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
#ifndef Bst_H
#define BSH_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif


```
```queue.cpp
#include "bst.h"
#include <iostream>

using namespace std;
//NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree){
    if(tree == Nil){
        return true;
    } else {
        return false;
    }
}

void createTree(BinTree &tree){
    tree = Nil;
}

node alokasi(int angkaInput){
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus){
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru){
    if(tree == Nil){
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    } else if(nodeBaru->angka < tree->angka){
        insertNode(tree->left, nodeBaru);
    } else if(nodeBaru->angka > tree->angka){
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari){
    if(isEmpty(tree) == true){
        cout << "Tree kosong!" << endl;
    } else {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(angkaCari < nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(angkaCari > nodeBantu->angka){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(angkaCari == nodeBantu->angka){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            //menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if(parent != Nil){
                cout << "Parent : " << parent->angka << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != Nil){
                cout << "Sibling : " << sibling->angka << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != Nil){
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            } else if(nodeBantu->left == Nil){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != Nil){
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            } else if(nodeBantu->right == Nil){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree){ //tengah - kiri - kanan atau root - child kiri - child kanan
    if(tree == Nil){
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree){ //kiri - tengah - kanan atau child kiri - root - child kanan
    if(tree == Nil){
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree){ //kiri - kanan - tengah atau child kiri - child kanan - root
    if(tree == Nil){
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}



bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (angka < tree->angka) {
            return deleteNode(tree->left, angka);
        } else if (angka > tree->angka) {
            return deleteNode(tree->right, angka);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil) {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil) {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil) {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                //salin data successor ke node saat ini
                tree->angka = successor->angka;
                //hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; //berhasil dihapus
        }
    }
}

node mostRight(BinTree tree){
    while (tree->right != Nil){
        tree = tree->right;
    }
    return tree;    
}

node mostLeft(BinTree tree){
    while (tree->left != Nil){
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree){
    if(tree == Nil){
        return;
    } else {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree){ //mengembalikan jumlah semua node
    if(isEmpty(tree) == true){
        return 0;
    } else {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree){ //mengembalikan jumlah level tree
    if(isEmpty(tree) == true){
        return -1; //tree kosong jika height = -1
    } else {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr){
            maxHeight = hl;
        } else {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
   cout << endl;
}
```
```main.cpp
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih){
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if(deleteNode(tree, angka)){
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                } else {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9: 
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;
        
        case 10:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
                cout << endl;
            } else {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if(isEmpty(tree) == true){
                cout << "Tree kosong!" << endl;
            } else {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```
Program guided 1 ini bertujuan untuk mengimplementasikan struktur data Binary Search Tree (BST) menggunakan Linked List (pointer) dalam bahasa C++. Setiap node dalam tree memiliki data berupa integer (angka) serta pointer left dan right yang menunjuk ke sub-tree kiri dan sub-tree kanan.

File bst.h berisi rancangan struktur data dan deklarasi fungsi-fungsi yang digunakan, seperti inisialisasi tree, pengecekan apakah tree kosong, alokasi memori untuk node baru, serta deklarasi fungsi operasi utama seperti insertNode, deleteNode, searchByData, dan fungsi traversal.

File bst.cpp berisi implementasi detail dari fungsi-fungsi tersebut. Di dalamnya terdapat logika aturan BST (nilai lebih kecil ke kiri, lebih besar ke kanan), algoritma traversal (PreOrder, InOrder, PostOrder), pencarian data, serta logika penghapusan node yang menangani berbagai kasus seperti penghapusan leaf, node dengan satu child, atau node dengan dua child.

File main.cpp adalah bagian utama yang menjalankan program. Di sini, tree dibuat dan pengguna disuguhkan menu interaktif untuk melakukan berbagai operasi, mulai dari menyisipkan angka, mencari data, menampilkan isi tree dengan berbagai metode traversal, hingga menghitung ukuran (size) dan kedalaman (height) dari tree tersebut.





## Unguided 

### 1. Soal Unguided 1-3
![Screenshot Soal 1](
![Screenshot Soal 2](
![Screenshot Soal 3](

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
//main1.cpp

#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    
    cout<<"-------------------"<<endl;
    cout<<" H  T | Queue info"<<endl;
    cout<<"-------------------"<<endl;

    CreateQueue(Q);
    printInfo(Q);

    enqueue(Q, 5);
    printInfo(Q);

    enqueue(Q, 2);
    printInfo(Q);

    enqueue(Q, 7);
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q);


    dequeue(Q); 
    printInfo(Q);

    enqueue(Q, 4); 
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q);

    dequeue(Q); 
    printInfo(Q);
    
    return 0;
}

```
```C++
//main 2
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    
    cout<<"-------------------"<<endl;
    cout<<" H  T | Queue info"<<endl;
    cout<<"-------------------"<<endl;

    CreateQueue(Q);
    printInfo(Q);

    cout << "== Mengisi Penuh Queue ==" << endl;
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);
    printInfo(Q);

    cout << "== Dequeue 2x (Menciptakan 'Penuh Sementara') ==" << endl;
    dequeue(Q);
    dequeue(Q);
    printInfo(Q);

    cout << "== Enqueue 2x (Memicu Perbedaan Logika) ==" << endl;
    enqueue(Q, 6);
    printInfo(Q);
    
    enqueue(Q, 7);
    printInfo(Q);

    cout << "== Mengosongkan Queue ==" << endl;
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
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
```C++
//main 3
#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    
    cout<<"-------------------"<<endl;
    cout<<" H  T | Queue info"<<endl;
    cout<<"-------------------"<<endl;

    CreateQueue(Q);
    printInfo(Q);

    cout << "== Mengisi Penuh Queue ==" << endl;
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);
    printInfo(Q);

    cout << "== Dequeue 2x (Menciptakan 'Penuh Sementara) ==" << endl;
    dequeue(Q);
    dequeue(Q);
    printInfo(Q);

    cout << "== Enqueue 2x (Memicu Perbedaan Logika) ==" << endl;
    enqueue(Q, 6);
    printInfo(Q);
    
    enqueue(Q, 7);
    printInfo(Q);

    cout << "== Mengosongkan Queue ==" << endl;
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
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


#### Output 1
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan8_Modul8/soal1.png)

### Output 2
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan8_Modul8/soal2.png)

### Output 3
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan8_Modul8/soal3.png)

### Penjelasan
Penjelasan Soal 1: ADT Queue Array (Alternatif 1)

Bagian pertama program berfokus pada implementasi ADT Queue menggunakan representasi Array, spesifiknya Alternatif 1. Ini dicapai dengan mendefinisikan Type Queue (terdiri dari array info[5], head, dan tail) di file queue.h, serta mengimplementasikan prosedur dasarnya (CreateQueue, enqueue, printInfo, dequeue) di file queue.cpp. Sesuai Alternatif 1, head selalu 0 jika antrean tidak kosong, enqueue memajukan tail, dan dequeue mengambil data di head (indeks 0) lalu menggeser semua sisa elemen ke depan.

Di dalam main.cpp (sesuai Gambar 8-18 ), program melakukan serangkaian operasi enqueue dan dequeue. Awalnya, data 5, 2, dan 7 di-enqueue, menghasilkan state H 0 T 2 | 5 2 7.

Saat dequeue pertama dipanggil, program mengambil nilai 5. Alih-alih memindahkan head, program menggeser elemen '2' dan '7' ke indeks 0 dan 1. Hasilnya, state list berubah menjadi H 0 T 1 | 2 7. Sisa operasi (enqueue(4), lalu dequeue 3x) mengikuti logika pergeseran yang sama hingga antrean kembali kosong (H -1 T -1), menghasilkan output yang sesuai dengan Gambar 8-17 .

Penjelasan Soal 2: ADT Queue Array (Alternatif 2)

Bagian kedua program berfokus pada implementasi ADT Queue Alternatif 2. Prosedur di queue.cpp dimodifikasi. dequeue kini menjadi efisien dengan hanya memajukan head. Namun, enqueue kini memiliki logika tambahan: jika tail telah mencapai akhir array (MAX_QUEUE-1) tetapi head tidak di indeks 0 (kondisi "penuh semu" ), enqueue akan menggeser semua elemen yang ada ke awal array untuk menciptakan ruang di belakang.

Di dalam main.cpp (versi modifikasi), program dirancang untuk memicu kondisi penuh semu. Pertama, antrean diisi penuh (H 0 T 4 | 1 2 3 4 5). Kemudian, dequeue dipanggil 2 kali, memajukan head. State list menjadi H 2 T 4 | 3 4 5.

Saat enqueue(6) dipanggil, kondisi penuh semu terdeteksi (tail == 4 dan head != 0). Logika Alternatif 2 terpicu: elemen '3', '4', '5' digeser ke indeks 0, 1, dan 2. head direset ke 0 dan tail menjadi 3. State akhir berubah menjadi H 0 T 3 | 3 4 5 6, yang membuktikan operasi pergeseran telah berhasil.

Penjelasan Soal 3: ADT Queue Array (Alternatif 3 / Circular)

Bagian ketiga program mengimplementasikan ADT Queue Alternatif 3, yang dikenal sebagai Circular Buffer. Prosedur di queue.cpp dimodifikasi total untuk menggunakan operasi modulo (%). enqueue dan dequeue kini memajukan head dan tail dengan membungkus indeks kembali ke 0 jika telah mencapai akhir array. Logika ini sepenuhnya menghilangkan kebutuhan untuk pergeseran elemen.

Di dalam main.cpp (menggunakan main.cpp modifikasi yang sama dengan Soal 2), program sengaja menciptakan kondisi penuh semu. Setelah enqueue 5x dan dequeue 2x, state list menjadi H 2 T 4 | 3 4 5.

Saat enqueue(6) dipanggil, logika Alternatif 3 yang berbeda dieksekusi. Alih-alih menggeser, tail "berputar": tail baru dihitung sebagai (4 + 1) % 5, yang menghasilkan 0. Elemen '6' disisipkan di info[0]. State akhir berubah menjadi H 2 T 0 | 3 4 5 6 (dicetak secara sirkular), yang secara jelas menunjukkan perbedaan implementasi dari Alternatif 2.

## Kesimpulan
Program guided ini mengimplementasikan struktur data Queue menggunakan array statis dengan prinsip FIFO (First In First Out). Implementasi menggunakan pendekatan Queue Linear Statis dimana head tetap pada posisi awal dan elemen digeser saat dequeue, dengan kapasitas terbatas sebanyak 5 elemen. Program demonstrasi menampilkan operasi enqueue untuk penambahan data, dequeue untuk penghapusan data, serta viewQueue untuk menampilkan isi antrian, memperkuat pemahaman tentang mekanisme dasar antrian dalam pemrosesan data berurutan.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

