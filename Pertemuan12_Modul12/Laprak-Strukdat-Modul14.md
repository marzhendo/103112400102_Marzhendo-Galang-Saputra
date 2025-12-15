# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Graph merupakan struktur data non-linier yang digunakan untuk merepresentasikan hubungan antar data dalam bentuk simpul (vertex) dan sisi (edge). Setiap simpul merepresentasikan suatu objek, sedangkan sisi menunjukkan hubungan antar simpul tersebut. Struktur data graph banyak digunakan untuk memodelkan permasalahan yang memiliki hubungan kompleks, seperti jaringan komputer, peta, serta hubungan antar entitas dalam sistem informasi [71].

Berdasarkan arah hubungannya, graph dibedakan menjadi directed graph dan undirected graph. Directed graph memiliki sisi yang berarah, sedangkan undirected graph memiliki sisi dua arah. Beberapa istilah penting dalam graph antara lain degree, in-degree, dan out-degree, yang digunakan untuk menyatakan jumlah hubungan yang dimiliki suatu simpul [73].

Graph dapat direpresentasikan ke dalam memori komputer menggunakan beberapa metode, di antaranya Adjacency Matrix dan Adjacency List. Representasi adjacency matrix menggunakan matriks dua dimensi, sedangkan adjacency list menyimpan daftar simpul yang terhubung pada setiap simpul. Adjacency list lebih efisien dalam penggunaan memori dan sering diimplementasikan menggunakan linked list, terutama untuk graph dengan jumlah edge yang relatif sedikit [74][77].

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

```
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

typedef struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode node1, adrNode node2);
void DeleteNode(Graph &G, infoGraph X);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif

```
```
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```
```main.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'D', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== TRAVERSAL ===" << endl;
    cout << "BFS Traversal: ";
    PrintBFS(G, 'A');
    cout << endl;
    cout << "DFS Traversal: ";
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== DELETE NODE ===" << endl;
    DeleteNode(G, 'E');
    if (FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak ditemukan" << endl;
    }
    cout << endl;
    
    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    cout << "BFS Traversal: ";
    PrintBFS(G, 'A');
    cout << endl;
    cout << "DFS Traversal: ";
    PrintDFS(G, 'A');
    cout << endl;

    return 0;
}

```
Program guided 1 ini bertujuan untuk mengimplementasikan struktur data Graph menggunakan bahasa C++ dengan pendekatan Adjacency List. Graph yang dibangun bersifat Undirected Graph, di mana setiap simpul (node) dapat saling terhubung dua arah melalui sisi (edge). Program ini juga mengimplementasikan algoritma traversal Breadth First Search (BFS) dan Depth First Search (DFS) untuk menelusuri graph.

File graph.h berisi perancangan struktur data dan deklarasi fungsi-fungsi yang digunakan. Struktur Graph memiliki pointer First yang menunjuk ke node pertama. Setiap ElmNode menyimpan informasi node (info), status kunjungan (visited), pointer ke daftar edge (firstEdge), serta pointer Next untuk menghubungkan node-node dalam graph. Struktur ElmEdge merepresentasikan hubungan antar node dengan menyimpan alamat node tujuan. Pada file ini juga dideklarasikan fungsi dasar seperti CreateGraph, InsertNode, ConnectNode, DeleteNode, FindNode, serta fungsi traversal BFS dan DFS. 

File graph.cpp berisi implementasi detail dari seluruh fungsi yang telah dideklarasikan pada header. Proses penambahan node dilakukan dengan konsep insert last, sedangkan penambahan edge dilakukan dengan insert first pada daftar edge. Fungsi ConnectNode menghubungkan dua node secara dua arah (undirected), sementara DeleteNode menghapus node beserta seluruh edge yang terhubung dengannya untuk mencegah dangling pointer dan kebocoran memori. Traversal BFS diimplementasikan menggunakan struktur data queue, sedangkan DFS menggunakan stack, dengan mekanisme penandaan visited untuk mencegah node dikunjungi lebih dari satu kali. 

File main.cpp merupakan program utama yang menjalankan simulasi graph. Pada file ini, graph diinisialisasi terlebih dahulu, kemudian beberapa node (A–F) ditambahkan dan dihubungkan sesuai skenario. Program menampilkan representasi graph dalam bentuk adjacency list, melakukan traversal BFS dan DFS dari node awal tertentu, serta mendemonstrasikan operasi penghapusan node untuk melihat bagaimana struktur graph berubah secara dinamis setelah node dan edge terkait dihapus.





## Unguided 

### 1. Soal Unguided 1-3
![Screenshot Soal 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan12_Modul12/soal1.png)
![Screenshot Soal 2-3](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan12_Modul12/soal2-3.png)

```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);

void InsertNode(Graph &G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
adrNode FindNode(Graph G, infoGraph data);

void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);

void PrintBFS(Graph G, adrNode N);
void PrintDFS(Graph G, adrNode N);

#endif
```
```c++
#include "graph.h"
#include <queue>
#include <stack>

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode AlokasiNode(infoGraph data) {
    adrNode newNode = new ElmNode;
    newNode->info = data;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    return newNode;
}

adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = nodeTujuan;
    newEdge->Next = NULL;
    return newEdge;
}

void InsertNode(Graph &G, infoGraph data) {
    adrNode newNode = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = newNode;
    } else {
        adrNode P = G.First;
        while (P->Next != NULL) {
            P = P->Next;
        }
        P->Next = newNode;
    }
}

adrNode FindNode(Graph G, infoGraph data) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == data) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        adrEdge edge1 = AlokasiEdge(node2);
        edge1->Next = node1->firstEdge;
        node1->firstEdge = edge1;

        adrEdge edge2 = AlokasiEdge(node1);
        edge2->Next = node2->firstEdge;
        node2->firstEdge = edge2;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    ResetVisited(G);
    
    if (N == NULL) {
        return;
    }

    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode currNode = Q.front();
        Q.pop();
        cout << currNode->info << " ";

        adrEdge E = currNode->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}

void PrintDFS(Graph G, adrNode N) {
    ResetVisited(G);

    if (N == NULL) {
        return;
    }

    stack<adrNode> S;
    S.push(N);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode currNode = S.top();
        S.pop();

        if (currNode->visited == 0) {
            currNode->visited = 1;
            cout << currNode->info << " ";

            adrEdge E = currNode->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0) {
                    S.push(E->Node);
                }
                E = E->Next;
            }
        }
    }
    cout << endl;
}
```
```C++
//main
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'C', 'G');
    ConnectNode(G, 'D', 'H');
    ConnectNode(G, 'E', 'H');
    ConnectNode(G, 'F', 'H');
    ConnectNode(G, 'G', 'H');

    cout << "=== INFORMASI GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    adrNode StartNode = FindNode(G, 'A');

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintDFS(G, StartNode);
    PrintBFS(G, StartNode);

    return 0;
}

```


### Output Soal1:

=== INFORMASI GRAPH ===
Node A terhubung ke: C B 
Node B terhubung ke: E D A 
Node C terhubung ke: G F A 
Node D terhubung ke: H B 
Node E terhubung ke: H B 
Node F terhubung ke: H C 
Node G terhubung ke: H C 
Node H terhubung ke: G F E D 

=== HASIL TRAVERSAL ===
DFS Traversal: A B D H E F C G
BFS Traversal: A C B G F E D H



#### Output 1
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan12_Modul12/unguided/output.png)

### Penjelasan
Program Unguided ini bertujuan untuk menerapkan secara mandiri konsep struktur data Graph menggunakan bahasa C++ dengan representasi Adjacency List. Graph yang dibangun bersifat Undirected Graph, di mana setiap node dapat terhubung ke node lain secara dua arah melalui edge. Program ini juga mengimplementasikan algoritma traversal Depth First Search (DFS) dan Breadth First Search (BFS) sebagai bentuk penerapan konsep penelusuran graph.

File graph.h berisi definisi struktur data utama yang digunakan, yaitu Graph, ElmNode, dan ElmEdge. Setiap node menyimpan informasi berupa karakter, status kunjungan (visited), pointer ke daftar edge, serta pointer ke node berikutnya. File ini juga mendeklarasikan fungsi-fungsi dasar seperti pembuatan graph, alokasi node dan edge, penambahan node, penghubungan node, pencarian node, serta fungsi traversal DFS dan BFS. 


File graph.cpp berisi implementasi dari seluruh fungsi yang telah dideklarasikan pada file header. Proses penambahan node dilakukan dengan konsep insert last pada list utama graph, sedangkan penghubungan antar node dilakukan dengan menambahkan edge pada awal daftar edge masing-masing node. Algoritma DFS diimplementasikan menggunakan struktur data stack, sedangkan BFS menggunakan queue, dengan memanfaatkan variabel visited untuk memastikan setiap node hanya dikunjungi satu kali selama proses traversal. Fungsi ResetVisited digunakan untuk mengatur ulang status kunjungan sebelum traversal dilakukan. 

File main.cpp merupakan bagian utama program yang digunakan untuk menguji dan mendemonstrasikan implementasi graph. Pada file ini, graph diinisialisasi kemudian diisi dengan beberapa node (A sampai H) dan dihubungkan sesuai dengan skenario tertentu. Program menampilkan informasi graph dalam bentuk adjacency list, kemudian melakukan traversal DFS dan BFS dimulai dari node awal yang telah ditentukan untuk melihat urutan kunjungan node berdasarkan masing-masing algoritma traversal.

## Kesimpulan
Graph digunakan untuk merepresentasikan hubungan antar entitas secara visual dan struktural. Implementasi dalam laporan ini berhasil membangun Undirected Graph menggunakan Adjacency List di C++, lengkap dengan fungsi dasar seperti penambahan node dan edge. Algoritma traversal DFS (Depth First Search) dan BFS (Breadth First Search) juga berhasil diimplementasikan menggunakan stack dan queue, masing-masing, untuk menelusuri graph secara efisien, dengan mekanisme `visited` untuk mencegah kunjungan berulang.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

