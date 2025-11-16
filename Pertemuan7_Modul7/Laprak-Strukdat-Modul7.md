# <h1 align="center">Laporan Praktikum Modul 6 - Double Linked List</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Stack atau tumpukan adalah salah satu struktur data linier yang bekerja dengan prinsip LIFO (Last In First Out), yaitu elemen yang dimasukkan terakhir akan dikeluarkan terlebih dahulu [26]. Struktur data ini hanya memiliki satu titik akses data, yaitu bagian TOP, tempat terjadinya operasi penambahan (push) dan penghapusan (pop) elemen.

Struktur stack banyak digunakan dalam berbagai aplikasi informatika seperti proses pemanggilan prosedur, perhitungan ekspresi aritmatika, rekursi, backtracking, serta berbagai algoritma lanjutan lainnya [26]. Representasi stack paling sering menggunakan array atau tabel, karena operasi dilakukan hanya di satu sisi, yaitu pada elemen teratas [27].

Secara fungsional, operasi utama pada stack terdiri dari [28–29]:

CreateEmpty(S) – Membuat stack kosong.

IsEmpty(S) – Mengecek apakah stack kosong (TRUE jika kosong).

Push(E, S) – Menambahkan elemen baru E ke puncak stack.

Pop(S) – Menghapus elemen dari puncak stack.

Stack dapat diimplementasikan menggunakan array dengan variabel tambahan TOP_PTR sebagai penunjuk posisi elemen teratas. Jika TOP_PTR = -1, maka stack dalam keadaan kosong. Operasi push akan menambah nilai TOP_PTR, sedangkan pop akan menguranginya [30–31].

Selain itu, stack juga digunakan dalam konversi dan evaluasi ekspresi, misalnya notasi postfix, yang merupakan bentuk ekspresi aritmatika tanpa tanda kurung dan mengikuti urutan prioritas operator. Compiler menggunakan stack untuk mentransformasikan ekspresi infix menjadi postfix, sehingga proses evaluasi menjadi lebih efisien [34–35].

Dengan demikian, stack merupakan struktur data penting dalam pemrograman karena kemampuannya mengatur data secara teratur, mendukung efisiensi algoritma, dan menjadi dasar dari berbagai mekanisme sistem seperti pemanggilan fungsi rekursif dan manajemen memori [26–35].
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

```stack.h
#ifndef STACK
#define STACK
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
void searchData(stack listStack, int data);

#endif

```
```stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}


```
```main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program guided 1 ini bertujuan untuk mengimplementasikan struktur data Stack (Tumpukan) menggunakan Linked List dalam bahasa C++. Setiap node dalam stack memiliki data berupa angka integer dan pointer next yang menunjuk ke node berikutnya.
File stack.h berisi rancangan struktur data dan daftar fungsi yang digunakan. File stack.cpp berisi isi dari fungsi-fungsi tersebut, seperti membuat stack baru, menambah data di puncak stack (push), menghapus data dari puncak (pop), menampilkan seluruh isi stack, mengubah data pada posisi tertentu (update), serta mencari data yang sudah ada dalam stack.
Sementara main.cpp adalah bagian utama yang menjalankan program. Di sini dibuat beberapa node dengan nilai 1 hingga 5, lalu node-node tersebut dimasukkan ke dalam stack menggunakan operasi push, ditampilkan isinya, kemudian dilakukan operasi pop sebanyak 2 kali untuk menghapus elemen teratas, dan diuji proses update serta pencarian data.
Hasil output program menampilkan konfirmasi setiap operasi yang dilakukan, isi stack sebelum dan sesudah dilakukan proses push dan pop, kemudian setelah pengguna memperbarui data pada posisi tertentu melalui input interaktif, serta hasil pencarian data yang dicari apakah ditemukan beserta posisinya atau tidak ditemukan dalam stack.
Secara sederhana, program ini membantu memahami bagaimana cara menambah, menampilkan, menghapus, dan mengubah data pada struktur linked list dengan prinsip LIFO (Last In First Out) dimana elemen terakhir yang masuk adalah yang pertama keluar, serta bagaimana melakukan pencarian data di dalamnya.

### 2. Guided 2

```stack.h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

// Ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable {
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif

```
```stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s){
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX - 1;
}

void createStack(stackTable &s){
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    // index = top - (posisi - 1)
    int idx = s.top - (posisi - 1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }
    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
} 

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; i--){
            cout << s.data[i] << " ";
        }
        cout << endl;
    }
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; i--){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan dalam stack!" << endl;
    }
    cout << endl;
}



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
Program guided 2 ini bertujuan untuk mengimplementasikan struktur data Stack (Tumpukan) menggunakan Array (struktur data statis) dalam bahasa C++. Setiap stack memiliki kapasitas maksimum yang ditentukan oleh konstanta MAX dan menggunakan indeks top untuk menandai posisi elemen teratas.
File stack.h berisi rancangan struktur data dan daftar fungsi yang digunakan. Di dalamnya terdapat struktur stackTable yang memiliki array data dengan kapasitas maksimal 10 elemen dan variabel top yang bernilai -1 ketika stack kosong. File stack.cpp berisi isi dari fungsi-fungsi tersebut, seperti membuat stack baru dengan menginisialisasi top menjadi -1, mengecek apakah stack kosong atau penuh, menambah data di puncak stack (push), menghapus data dari puncak (pop), menampilkan seluruh isi stack dari top ke bottom, mengubah data pada posisi tertentu (update) dengan perhitungan indeks dari top, serta mencari data yang sudah ada dalam stack.
Sementara main.cpp adalah bagian utama yang menjalankan program. Di sini dibuat stack kemudian diisi dengan angka 1 hingga 5 menggunakan operasi push, ditampilkan isinya sehingga terlihat urutan 5, 4, 3, 2, 1 dari top ke bottom, kemudian dilakukan operasi pop sebanyak 2 kali untuk menghapus elemen teratas, dan diuji proses update pada posisi 2, 1, dan 4 yang dihitung dari top, serta pencarian data bernilai 4 dan 9.
Hasil output program menampilkan konfirmasi setiap operasi yang dilakukan, isi stack sebelum dan sesudah dilakukan proses push dan pop yang menunjukkan prinsip LIFO, kemudian setelah pengguna memperbarui data pada posisi tertentu melalui input interaktif dengan posisi dihitung dari elemen teratas (1-based indexing), serta hasil pencarian data yang menampilkan posisi data jika ditemukan atau pesan data tidak ditemukan jika tidak ada dalam stack.
Secara sederhana, program ini membantu memahami bagaimana cara menambah, menampilkan, menghapus, dan mengubah data pada struktur array dengan prinsip LIFO (Last In First Out) dimana elemen terakhir yang masuk adalah yang pertama keluar, dengan batasan kapasitas maksimum yang telah ditentukan, serta bagaimana melakukan pencarian data dan validasi posisi di dalamnya.

## Unguided 

### 1. Soal Unguided 1-3
![Screenshot Soal 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal1.png)
![Screenshot Soal 2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal2.png)
![Screenshot Soal 3](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Soal3.png)

```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int MAX_STACK = 20;

typedef int infotype;

struct Stack {
    infotype info[MAX_STACK];
    int top;
};

bool isEmpty(Stack S);
bool isFull(Stack S);

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);

void getInputStream(Stack &S);

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
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
```C++
//soal2
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
```C++
//soal3
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Soal1:

Hello world!
[TOP] 9 2 4 3 
balik stack
[TOP] 3 4 2 9 

```
```
### Output Soal2:
Hello world!
[TOP] 9 8 4 3 3 2 
balik stack
[TOP] 2 3 3 4 8 9 
```
```
### Output Soal3:
Hello world!
4729601
[TOP] 1 0 6 9 2 7 4 
balik stack
[TOP] 4 7 2 9 6 0 1
```

##### Output 1
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Output%20Final.png)

### Output 2
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Output%20Final.png)

### Output 3
![Screenshot Output Unguided 1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan5_Modul5/Output%20Final.png)

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

