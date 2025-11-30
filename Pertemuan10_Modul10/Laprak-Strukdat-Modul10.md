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
![Screenshot Soal 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan10_Modul10/soal1.png)
![Screenshot Soal 2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan10_Modul10/soal2.png)
![Screenshot Soal 3](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan10_Modul10/soal3.png)

```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
struct Node {
    infotype info;
    Node *left;
    Node *right;
};
typedef Node* address;

address alokasi(infotype x);                                  
void insertNode(address &root, infotype x);                   
address findNode(infotype x, address root);                   
void printInOrder(address root);                              

int hitungKedalaman(address root);                            
int hitungJumlahNode(address root);                           
int hitungTotal(address root);                                

void printPreOrder(address root);                             
void printPostOrder(address root);                            

#endif

```
```c++
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {           
    address p = new Node;
    p->info  = x;
    p->left  = Nil;
    p->right = Nil;
    return p;
}

void insertNode(address &root, infotype x) {   
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

void printInOrder(address root) {              
    if (root != Nil) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

int hitungKedalaman(address root) {
    if (root == Nil) return 0;
    int L = hitungKedalaman(root->left);
    int R = hitungKedalaman(root->right);
    return (L > R ? L : R) + 1;
}

int hitungJumlahNode(address root) {          
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left)
             + hitungJumlahNode(root->right);
}

int hitungTotal(address root) {              
    if (root == Nil) return 0;
    return root->info + hitungTotal(root->left)
                      + hitungTotal(root->right);
}

void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {           
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " ";
    }
}

```
```C++
//soal1
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);     
    cout << endl;

    return 0;
}

```
```C++
//soal2
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);
    cout << endl;

    cout << "kedalaman : "   << hitungKedalaman(root)    << endl;
    cout << "jumlah node : " << hitungJumlahNode(root)   << endl;
    cout << "total : "       << hitungTotal(root)        << endl;

    return 0;
}

```
```C++
//soal3
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);

    cout << "Pre-order  : ";
    printPreOrder(root);
    cout << endl;

    cout << "Post-order : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}

```


### Output Soal1:

Hello world!
1 - 2 - 3 - 4 - 5 - 6 - 7 -


### Output Soal2:
Hello world!
1 - 2 - 3 - 4 - 5 - 6 - 7 - 
kedalaman : 7
jumlah node : 7
total : 28


### Output Soal3:
Pre-order  : 4 2 1 3 6 5 7 
Post-order : 1 3 2 5 7 6 4


#### Output 1
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan10_Modul10/output1.png)

### Output 2
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan10_Modul10/output2.png)

### Output 3
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan10_Modul10/output3.png)

### Penjelasan
Penjelasan Soal 1: Implementasi Dasar BST (Insert & InOrder)

Bagian pertama program berfokus pada implementasi dasar ADT Binary Search Tree (BST) menggunakan pointer. Struktur data didefinisikan sebagai struct Node di file bstree.h, sementara logika prosedurnya seperti alokasi dan insertNode diimplementasikan di bstree.cpp. Logika insertNode memastikan aturan BST terjaga: nilai yang lebih kecil dari root akan masuk ke subtree kiri, dan yang lebih besar ke subtree kanan.

Di dalam soal1.cpp, program melakukan serangkaian operasi insert data secara berurutan mulai dari angka 1 hingga 7. Karena data dimasukkan secara urut menaik, tree yang terbentuk menjadi tidak seimbang (skewed) atau miring ke kanan, sehingga bentuknya menyerupai Linked List linier.

Saat prosedur printInOrder dipanggil, program menelusuri tree dengan urutan Left-Root-Right. Hasilnya, data ditampilkan secara terurut menaik (1 - 2 - 3 - 4 - 5 - 6 - 7), membuktikan bahwa data telah tersimpan dengan benar dalam struktur BST meskipun bentuk tree-nya belum optimal.

Penjelasan Soal 2: Operasi Perhitungan pada Tree

Bagian kedua program memperluas fungsionalitas dengan menambahkan operasi statistik pada tree di file bstree.cpp. Fungsi rekursif ditambahkan untuk menghitung atribut tree, yaitu hitungKedalaman untuk mencari tinggi tree, hitungJumlahNode untuk menghitung total elemen, dan hitungTotal untuk menjumlahkan nilai seluruh data.

Di dalam soal2.cpp, inisialisasi tree yang dilakukan sama persis dengan Soal 1 (memasukkan angka 1-7 secara urut). Setelah tree terbentuk, program memanggil fungsi-fungsi perhitungan tersebut.

Karena bentuk tree miring ke kanan (right-skewed), hasil kedalaman (height) akan setara dengan jumlah nodenya (7 level), yang menunjukkan kasus terburuk (worst case) dari BST. Output program menampilkan hasil perhitungan kedalaman, jumlah node, dan total penjumlahan nilai secara akurat.

Penjelasan Soal 3: Traversal dan Efek Urutan Insert

Bagian ketiga program mengeksplorasi pengaruh urutan input data terhadap bentuk tree dan hasil traversal. Logika traversal tambahan yaitu printPreOrder (Root-Left-Right) dan printPostOrder (Left-Right-Root) diimplementasikan di file bstree.cpp.

Di dalam soal3.cpp, data dimasukkan dengan urutan acak namun strategis (4, 2, 6, 1, 3, 5, 7). Dimulai dengan angka 4 sebagai root, angka-angka berikutnya mengisi sisi kiri dan kanan secara merata, menghasilkan tree yang seimbang (balanced tree).

Saat traversal dijalankan, printPreOrder menampilkan urutan 4 2 1 3 6 5 7, yang mencerminkan struktur hierarki dari root ke daun. Sebaliknya, printPostOrder menampilkan urutan 1 3 2 5 7 6 4, yang memproses anak terlebih dahulu sebelum induknya. Ini menunjukkan bahwa urutan penyisipan data sangat mempengaruhi struktur internal BST dibandingkan dengan Soal 1.

## Kesimpulan
Program ini mengimplementasikan struktur data Binary Search Tree (BST) menggunakan representasi Linked List dinamis dengan prinsip hierarki di mana nilai anak kiri selalu lebih kecil dari root dan anak kanan lebih besar. Implementasi ini memanfaatkan pointer dan alokasi memori dinamis, memungkinkan struktur tree tumbuh secara fleksibel tanpa batasan kapasitas statis. Melalui tugas Guided dan Unguided, program mendemonstrasikan penerapan logika rekursif yang efisien untuk berbagai operasi seperti traversal (PreOrder, InOrder, PostOrder), pencarian data, serta perhitungan statistik tree (kedalaman dan total node). Hasil percobaan juga memperkuat pemahaman mengenai karakteristik alami BST, di mana urutan penyisipan data (insertion) sangat mempengaruhi efisiensi dan bentuk tree, menghasilkan struktur skewed (miring) pada input terurut dan struktur yang lebih seimbang (balanced) pada input acak.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

