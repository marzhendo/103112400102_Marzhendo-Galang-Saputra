# <h1 align="center">Laporan Praktikum Modul 11 - MLL</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Multi Linked List merupakan variasi dari struktur data Linked List di mana setiap simpul (node) memiliki kemungkinan untuk memuat pointer ke lebih dari satu node lainnya. Struktur ini dianggap sebagai modifikasi dari single atau double linked list agar dapat menangani kasus relasi data yang lebih kompleks. Multi Linked List sering digunakan untuk merepresentasikan hubungan hierarkis seperti Parent-Child, struktur Tree, atau Graph. [2]

Tujuan utama dari penggunaan Multi Linked List adalah untuk menggambarkan hubungan antar data yang tidak bersifat linear tunggal. Terdapat dua jenis relasi utama yang dapat dimodelkan menggunakan struktur ini:

Relasi 1-ke-N (One-to-Many): Di mana satu elemen pada list utama (parent) memiliki hubungan dengan banyak elemen lain (children).

Relasi N-ke-M (Many-to-Many): Di mana banyak elemen dari satu himpunan dapat berhubungan dengan banyak elemen di himpunan lainnya. [3]

Secara bentuk implementasi, Multi Linked List dapat diwujudkan dalam dua mekanisme utama:

List inside a List: Sebuah list yang berada di dalam list lain.

Koneksi antar List: Hubungan yang dibentuk antara dua atau lebih list yang terpisah. [3]

Dalam kasus relasi 1-N (contoh: Pegawai dan Anak), elemen pada list utama (Pegawai) bertindak sebagai parent yang memiliki pointer tambahan untuk menunjuk ke elemen pertama dari list anak (child list). Child list ini merupakan sub-list yang "menempel" atau menjadi anggota dari elemen parent tersebut. [5]

Sedangkan untuk kasus relasi N-M (contoh: Mahasiswa dan Mata Kuliah), struktur data dapat dimodifikasi dengan menyisipkan sebuah list relasi di dalam setiap elemen mahasiswa. List relasi ini berfungsi untuk menunjuk ke berbagai mata kuliah yang diambil oleh mahasiswa tersebut, sehingga memungkinkan satu mahasiswa terhubung ke banyak mata kuliah, dan sebaliknya. [18]

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
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif
```
```queue.cpp
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```
```main.cpp
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```
Program guided 1 ini bertujuan untuk mengimplementasikan struktur data Multi Linked List (MLL) menggunakan bahasa C++. MLL di sini merepresentasikan hubungan 1-ke-N antara Kategori Makanan (sebagai Parent) dan Menu Makanan (sebagai Child). Setiap node parent memiliki sebuah sub-list yang berisi node child, sehingga terbentuk struktur hierarkis.

File mll.h berisi rancangan struktur data dan deklarasi fungsi-fungsi yang digunakan. Struktur nodeParent dirancang untuk menyimpan data kategori serta memiliki pointer next dan prev (Double Linked List) untuk navigasi antar kategori, dan yang terpenting, sebuah variabel listAnak untuk menampung data menu. Struktur nodeChild juga menggunakan Double Linked List untuk menyimpan data detail makanan seperti ID, nama, dan harga. File ini juga mendeklarasikan fungsi operasi dasar seperti createList, insert, delete, find, dan update untuk kedua jenis node.

File mll.cpp berisi implementasi detail dari fungsi-fungsi tersebut. Di dalamnya terdapat logika manipulasi linked list yang kompleks, seperti penambahan node parent di awal/akhir/tengah, penambahan node child ke dalam parent tertentu, serta logika penghapusan parent yang secara otomatis juga harus menghapus seluruh list child yang dimilikinya (untuk mencegah kebocoran memori). Fungsi pencarian (find) dan pembaruan (update) juga diimplementasikan dengan menelusuri (traversal) list induk dan list anak secara bersarang (nested traversal).

File main.cpp adalah bagian utama yang menjalankan simulasi sistem restoran. Di sini, struktur MLL dibangun dari nol: list induk diinisialisasi, kemudian tiga kategori utama ("Makanan Berat", "Minuman", "Dessert") dibuat dan dihubungkan. Selanjutnya, berbagai menu makanan disisipkan ke dalam kategori yang sesuai. Pengguna kemudian disuguhkan demonstrasi operasi CRUD: pencarian data berdasarkan ID, pembaruan nama kategori dan harga makanan, hingga penghapusan item menu dan kategori tertentu untuk melihat bagaimana struktur data berubah secara dinamis.





## Unguided 

### 1. Soal Unguided 1-3
![Screenshot Soal 1](
![Screenshot Soal 2](
![Screenshot Soal 3](

```C++
#ifndef BSTREE_H
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
#include <string>

using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor; 
    float bobot; 
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNParent);
void insertLastParent(listParent &LParent, NodeParent newNParent);

void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev); 

void insertFirstChild(listChild &LChild, NodeChild newNChild);
void insertLastChild(listChild &LChild, NodeChild newNChild);

void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);
void deleteListChild(listChild &LChild);

void printMLLStructure(listParent LParent);

void searchHewanByEkor(listParent &LParent, bool tail);

#endif
```
```c++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return LParent.first == NULL;
}

bool isEmptyChild(listChild LChild) {
    return LChild.first == NULL;
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild C = new nodeChild;
    C->isidata.idHewan = idHwn;
    C->isidata.namaHewan = namaHwn;
    C->isidata.habitat = habitat;
    C->isidata.ekor = tail;
    C->isidata.bobot = weight;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
    NParent = NULL;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
    NChild = NULL;
}

void insertFirstParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        newNParent->next = LParent.first;
        LParent.first->prev = newNParent;
        LParent.first = newNParent;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNParent) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNParent;
        LParent.last = newNParent;
    } else {
        LParent.last->next = newNParent;
        newNParent->prev = LParent.last;
        LParent.last = newNParent;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent P = LParent.first;
        if (LParent.first == LParent.last) {
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = P->next;
            LParent.first->prev = NULL;
            P->next = NULL;
        }
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent P = NPrev->next;
        NPrev->next = P->next;
        if (P->next != NULL) {
            P->next->prev = NPrev;
        } else {
            LParent.last = NPrev;
        }
        P->next = NULL;
        P->prev = NULL;
        
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        newNChild->next = LChild.first;
        LChild.first->prev = newNChild;
        LChild.first = newNChild;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNChild) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNChild;
        LChild.last = newNChild;
    } else {
        LChild.last->next = newNChild;
        newNChild->prev = LChild.last;
        LChild.last = newNChild;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild C = LChild.first;
        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = C->next;
            LChild.first->prev = NULL;
            C->next = NULL;
        }
        deallocNodeChild(C);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild C = NPrev->next;
        NPrev->next = C->next;
        if (C->next != NULL) {
            C->next->prev = NPrev;
        } else {
            LChild.last = NPrev;
        }
        C->next = NULL;
        C->prev = NULL;
        deallocNodeChild(C);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent Kosong." << endl;
    } else {
        NodeParent P = LParent.first;
        int i = 1;
        while (P != NULL) {
            cout << "=== Parent " << i << " ===" << endl;
            cout << "ID Golongan : " << P->isidata.idGolongan << endl;
            cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

            if (isEmptyChild(P->L_Child)) {
                cout << "  (tidak ada child)" << endl;
            } else {
                NodeChild C = P->L_Child.first;
                int j = 1;
                while (C != NULL) {
                    cout << "  - Child " << j << " :" << endl;
                    cout << "      ID Hewan : " << C->isidata.idHewan << endl;
                    cout << "      Nama Hewan : " << C->isidata.namaHewan << endl;
                    cout << "      Habitat : " << C->isidata.habitat << endl;
                    cout << "      Ekor : " << C->isidata.ekor << endl;
                    cout << "      Bobot : " << C->isidata.bobot << endl;
                    C = C->next;
                    j++;
                }
            }
            cout << "--------------------------------" << endl;
            P = P->next;
            i++;
        }
    }
}

void searchHewanByEkor(listParent &LParent, bool tail) {
    if (isEmptyParent(LParent)) {
        cout << "List Parent Kosong." << endl;
        return;
    }

    NodeParent P = LParent.first;
    int idxParent = 1;
    bool found = false;

    while (P != NULL) {
        if (!isEmptyChild(P->L_Child)) {
            NodeChild C = P->L_Child.first;
            int idxChild = 1;
            while (C != NULL) {
                if (C->isidata.ekor == tail) {
                    found = true;
                    cout << "Data ditemukan pada list anak dari node parent " << P->isidata.namaGolongan << " pada posisi ke-" << idxChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << C->isidata.idHewan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << idxChild << endl;
                    cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                    cout << "Habitat : " << C->isidata.habitat << endl;
                    cout << "Ekor : " << C->isidata.ekor << endl; 
                    cout << "Bobot : " << C->isidata.bobot << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << P->isidata.idGolongan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << idxParent << endl;
                    cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                    cout << "---------------------------" << endl;
                    cout << endl;
                }
                C = C->next;
                idxChild++;
            }
        }
        P = P->next;
        idxParent++;
    }
    
    if (!found) {
        cout << "Data hewan dengan status ekor " << (tail ? "TRUE" : "FALSE") << " tidak ditemukan." << endl;
    }
}

```
```C++
//main
#include "MultiLL.h"
#include <iostream>

using namespace std;

int main() {
    listParent LP;
    createListParent(LP);

    NodeParent P1 = allocNodeParent("G001", "Aves");
    insertLastParent(LP, P1);

    NodeParent P2 = allocNodeParent("G002", "Mamalia");
    insertLastParent(LP, P2);

    NodeParent P3 = allocNodeParent("G003", "Pisces");
    insertLastParent(LP, P3);

    NodeParent P4 = allocNodeParent("G004", "Amfibi");
    insertLastParent(LP, P4);

    NodeParent P5 = allocNodeParent("G005", "Reptil");
    insertLastParent(LP, P5);

    NodeChild C1_1 = allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertLastChild(P1->L_Child, C1_1);
    
    NodeChild C1_2 = allocNodeChild("AV002", "Bebek", "Air", true, 2);
    insertLastChild(P1->L_Child, C1_2);

    NodeChild C2_1 = allocNodeChild("M001", "Harimau", "Hutan", true, 200);
    insertLastChild(P2->L_Child, C2_1);

    NodeChild C2_2 = allocNodeChild("M003", "Gorila", "Hutan", false, 160);
    insertLastChild(P2->L_Child, C2_2);

    NodeChild C2_3 = allocNodeChild("M002", "Kucing", "Darat", true, 4);
    insertLastChild(P2->L_Child, C2_3);

    NodeChild C4_1 = allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertLastChild(P4->L_Child, C4_1);

    cout << "=== HASIL INSERT ===" << endl;
    printMLLStructure(LP);
    cout << endl;

    cout << "=== HASIL SEARCHING (EKOR = FALSE) ===" << endl;
    searchHewanByEkor(LP, false);
    cout << endl;

    cout << "=== HASIL DELETE PARENT G004 (AMFIBI) ===" << endl;
    deleteAfterParent(LP, P3); 
    
    printMLLStructure(LP);

    return 0;
}
```


### Output Soal1:

=== HASIL INSERT ===
=== Parent 1 ===
ID Golongan : G001
Nama Golongan : Aves
  - Child 1 :
      ID Hewan : AV001
      Nama Hewan : Cendrawasih
      Habitat : Hutan
      Ekor : 1
      Bobot : 0.3
  - Child 2 :
      ID Hewan : AV002
      Nama Hewan : Bebek
      Habitat : Air
      Ekor : 1
      Bobot : 2
--------------------------------
=== Parent 2 ===
ID Golongan : G002
Nama Golongan : Mamalia
  - Child 1 :
      ID Hewan : M001
      Nama Hewan : Harimau
      Habitat : Hutan
      Ekor : 1
      Bobot : 200
  - Child 2 :
      ID Hewan : M003
      Nama Hewan : Gorila
      Habitat : Hutan
      Ekor : 0
      Bobot : 160
  - Child 3 :
      ID Hewan : M002
      Nama Hewan : Kucing
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
--------------------------------
=== Parent 4 ===
ID Golongan : G004
Nama Golongan : Amfibi
  - Child 1 :
      ID Hewan : AM001
      Nama Hewan : Kodok
      Habitat : Sawah
      Ekor : 0
      Bobot : 0.2
--------------------------------
=== Parent 5 ===
ID Golongan : G005
Nama Golongan : Reptil
  (tidak ada child)
--------------------------------

### Output Soal2:
=== HASIL SEARCHING (EKOR = FALSE) ===
Data ditemukan pada list anak dari node parent Mamalia pada posisi ke-2!
--- Data Child ---
ID Child : M003
Posisi dalam list anak : posisi ke-2
Nama Hewan : Gorila
Habitat : Hutan
Ekor : 0
Bobot : 160
---------------------------
--- Data Parent ---
ID Parent : G002
Posisi dalam list induk : posisi ke-2
Nama golongan : Mamalia
---------------------------

Data ditemukan pada list anak dari node parent Amfibi pada posisi ke-1!
--- Data Child ---
ID Child : AM001
Posisi dalam list anak : posisi ke-1
Nama Hewan : Kodok
Habitat : Sawah
Ekor : 0
Bobot : 0.2
---------------------------
--- Data Parent ---
ID Parent : G004
Posisi dalam list induk : posisi ke-4
Nama golongan : Amfibi
---------------------------


### Output Soal3:
=== HASIL DELETE PARENT G004 (AMFIBI) ===
=== Parent 1 ===
ID Golongan : G001
Nama Golongan : Aves
  - Child 1 :
      ID Hewan : AV001
      Nama Hewan : Cendrawasih
      Habitat : Hutan
      Ekor : 1
      Bobot : 0.3
  - Child 2 :
      ID Hewan : AV002
      Nama Hewan : Bebek
      Habitat : Air
      Ekor : 1
      Bobot : 2
--------------------------------
=== Parent 2 ===
ID Golongan : G002
Nama Golongan : Mamalia
  - Child 1 :
      ID Hewan : M001
      Nama Hewan : Harimau
      Habitat : Hutan
      Ekor : 1
      Bobot : 200
  - Child 2 :
      ID Hewan : M003
      Nama Hewan : Gorila
      Habitat : Hutan
      Ekor : 0
      Bobot : 160
  - Child 3 :
      ID Hewan : M002
      Nama Hewan : Kucing
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
--------------------------------
=== Parent 4 ===
ID Golongan : G005
Nama Golongan : Reptil
  (tidak ada child)
--------------------------------
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
--------------------------------
=== Parent 4 ===
ID Golongan : G005
Nama Golongan : Reptil
  (tidak ada child)
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
--------------------------------
=== Parent 4 ===
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
--------------------------------
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
--------------------------------
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
      Habitat : Darat
      Ekor : 1
      Habitat : Darat
      Ekor : 1
      Bobot : 4
      Habitat : Darat
      Ekor : 1
      Habitat : Darat
      Ekor : 1
      Habitat : Darat
      Ekor : 1
      Habitat : Darat
      Habitat : Darat
      Habitat : Darat
      Habitat : Darat
      Ekor : 1
      Bobot : 4
--------------------------------
=== Parent 3 ===
ID Golongan : G003
Nama Golongan : Pisces
  (tidak ada child)
--------------------------------
=== Parent 4 ===
ID Golongan : G005
Nama Golongan : Reptil
  (tidak ada child)
--------------------------------



#### Output 1
![Screenshot Output Unguided 1](
### Output 2
![Screenshot Output Unguided 1](
### Output 3
![Screenshot Output Unguided 1](

### Penjelasan
Program Unguided ini bertujuan untuk mengimplementasikan struktur data Multi Linked List menggunakan bahasa C++. Multi Linked List digunakan untuk merepresentasikan hubungan One-to-Many antara Golongan Hewan (Parent) dan Data Hewan (Child).

File MultiLL.h berisi definisi tipe data dan deklarasi fungsi. Struktur nodeParent dirancang untuk menyimpan data golongan hewan serta pointer L_Child yang merujuk pada list anak (hewan). Struktur nodeChild menyimpan detail data hewan seperti nama, habitat, status ekor, dan bobot.

File MultiLL.cpp berisi implementasi detail dari setiap fungsi. Di dalamnya terdapat logika operasi dasar seperti insert parent dan child, delete parent dan child (dengan penanganan khusus agar memory child dibebaskan sebelum parent dihapus), serta fungsi pencarian searchHewanByEkor yang menelusuri seluruh node untuk menemukan hewan berdasarkan kriteria tertentu.

File main.cpp adalah program utama yang mengeksekusi skenario. Pertama, list parent diinisialisasi dan diisi dengan data golongan. Kemudian, data hewan ditambahkan ke golongan yang sesuai. Program lalu melakukan pencarian hewan tanpa ekor dan menampilkan hasilnya. Terakhir, program menghapus golongan "Amfibi" (G004) dari list, yang secara otomatis juga menghapus data "Kodok" yang ada di dalamnya, dan menampilkan struktur akhir list.

## Kesimpulan
Program ini mengimplementasikan struktur data Multi Linked List menggunakan bahasa C++. Multi Linked List digunakan untuk merepresentasikan hubungan One-to-Many antara Golongan Hewan (Parent) dan Data Hewan (Child). Implementasi ini memanfaatkan pointer dan alokasi memori dinamis, memungkinkan struktur list tumbuh secara fleksibel tanpa batasan kapasitas statis. Melalui tugas Guided dan Unguided, program mendemonstrasikan penerapan logika rekursif yang efisien untuk berbagai operasi seperti traversal (PreOrder, InOrder, PostOrder), pencarian data, serta perhitungan statistik tree (kedalaman dan total node). Hasil percobaan juga memperkuat pemahaman mengenai karakteristik alami BST, di mana urutan penyisipan data (insertion) sangat mempengaruhi efisiensi dan bentuk tree, menghasilkan struktur skewed (miring) pada input terurut dan struktur yang lebih seimbang (balanced) pada input acak.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

