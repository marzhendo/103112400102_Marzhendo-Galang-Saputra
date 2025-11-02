# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Marzhendo Galang Saputra - 103112400102</p>

## Dasar Teori
Struktur data merupakan sebuah metode untuk menyimpan, mengorganisir, dan mengatur data di dalam media penyimpanan komputer sehingga data tersebut dapat diakses dan digunakan secara efisien [5]. Data itu sendiri adalah representasi dari fakta di dunia nyata, yang bisa berupa keterangan atau kenyataan yang direkam dan disajikan dalam bentuk tulisan, suara, gambar, sinyal, atau simbol [5]. Pemilihan dan pemakaian struktur data yang tepat dalam proses pemrograman sangat penting karena akan menghasilkan algoritma yang lebih jelas dan tepat, serta menjadikan program secara keseluruhan lebih efisien dan sederhana [5].

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

```C++
#include <iostream>

using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukkan value indeks ke-" << i << ":";
        cin >> arr[i];
    }   
    int j = 0;
    while (j < 5) {
        cout << "isi indeks ke-" << j << ":" << arr[j] << endl;
        j++;
    }
    return 0;
}
```
Guided 1 adalah contoh implementasi array 1 dimensi, dengan menggunakan perulangan for dan while. Pertama program mendeklarasikan sebuah variabel array integer bernama arr dengan panjang 5. Setelahnya program melakukan perulangan for untuk meminta user memasukkan input 5 nilai secara berurutan, yang kemudian disimpan ke dalam array dari index 0 sampe 4. Setelah perulangan for selesai, program berpindah ke perulangan while untuk menampilkan output data yang tadi sudah diinput.

### 2. Guided 2

```C++
#include <iostream>

using namespace std;

void tampilkanHasil(int arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Tampilkan hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);
    cout << endl;

    //perkalian matriks
    for (int i = 0; i < 2; i++) {                           //perulangan baris
        for (int j = 0; j < 2; j++) {                       //perulangan kolom
            for (int k = 0; k < 2; k++) {                   //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Tampilkan hasil perkalian : " << endl;
    tampilkanHasil(arrD);
    return 0;
}
```
Guided 2 adalah contoh implementasi array 2 dimensi. pertama program mendeklarasikan beberapa variabel array integer 2 dimensi ukuran 2x2, yaitu arrA dan arrB yg sudah diisi dengan value awal, serta arrC dan arrD yg digunakan untuk menampung hasil operasi. Setelahnya program akan melakukan operasi penjumlahan matriks dgn menggunakan nested for. untuk menjumlahkan setiap elemen pada arrA dan arrB, nantinya hasilnya akan disimpan ke dalam arrC. Setelah hasil penjumlahan ditampilkan, program berlanjut ke operasi perkalian matriks yg menggunakan 3 lapis perulangan for untuk menghitung dan menyimpan hasilnya ke dalam arrD. Output kedua arrC dan arrD akan ditampilkan dengan memanggil fungsi tampilkanHasil()

### 3. Guided 3

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored in ptr (adress of a): " << ptr << endl;
    cout << "Value pointed to by ptr: " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}

```
Guided 3 adalah implementasi konsep pointer, dengan fokus penggunaannya untuk melakukan operasi pass-by-reference melalui sebuah fungsi. Pertama program mendeklarasikan variabel integer a, b, dan sebuah pointer ptr. Setelahnya program mendemonstrasikan cara kerja dasar pointer dengan mengisi ptr menggunakan alamat dari variabel a, kemudian menampilkan perbandingan antara nilai asli, alamat memori, dan nilai yg diakses melalui pointer. Setelah proses demonstrasi selesai, program memanggil procedure tukar() dengan mengirimkan alamat dari a dan b. procedure ini lalu menggunakan alamat tersebut untuk menukar nilai kedua varabel secara langsung di memorinya, yang hasil outputnya akan ditampilkan di akhir program.

### 4. Guided 4

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 20, b = 30;
    int& ref = a;
    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ref (alias a): " << ref << endl;
    cout << "Alamat ref (alias a): " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50;" << endl;
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;

    return 0;
}

```
Guided 4 adalah implementasi konsep referene, dengan fokus penggunaannya sebagai alias variabel dan untuk melakukan operasi pass-by-reference. Pertama program mendeklarasikan variabel integer a, b. Setelahnya program mendemonstrasikan bahwa ref dan a berbagi alamat memori yg sama, lalu membuktikan bahwa mengubah nilai melalui ref juga akan mengubah nilai asli pada a. Setelah proses demonstrasi tersebut, program memanggil procedure tukar() yang argumennya diatur sbg reference. Dengan mekanisme ini, procedure tukar dapat menukar nilai asli dari a dan b secara langsung.

### 5. Guided 5

```C++
#include <iostream>
using namespace std;

int cariMAX(int arr[], int ukuran) {
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran) {
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++) {
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++) {
        totalKali *= arr[i];
    }
    cout << "Total perkalian : " << totalKali << endl;
}
int main() {
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan nilai array ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran) << endl;

    operasiAritmatika(arr, ukuran);
    return 0;
}

```
Guided 5 adalah implementasi yg membedakan antara func yg mengembailkan nilai/return dan procedure yg hanya menjalankan aksi. Pertama program meminta user untuk memasukkan 5 nilai yg akan disimpakn ke dalam sebuah array. Setelahnya, program akan memanggil func cariMax() yang bertugas mencari nilai terbesar dari sebuah array tersebut. Fungsi ini mereturn sebuah nilai integer, yg hasilnya kemudian akan ditampilkan langsung di dalam main. Kemudian program memanggil procedurre operasiAritmatika() yg bertipe void. Procedure ini tidak mereturn nilai, melainkan langsung menjalankan serangkaian perintah untuk menghitung dan menampilkan total penjumlahan serta perkalian dari seluruh elemen array ke layar.

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan
perkalian matriks 3x3

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int arrA[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {6, 7, 8}
    };
    int arrB[3][3] = {
        {1, 5, 3},
        {2, 2, 2},
        {8, 4, 6}
    };
    int arrC[3][3] = {0};
    int arrD[3][3] = {0};
    int arrE[3][3] = {0};

    //penjumlahan matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan matriks 3x3 : \n";
    tampilkanHasil(arrC);
    cout << endl;

    //pengurangan matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil pengurangan matriks 3x3 : \n";
    tampilkanHasil(arrD);
    cout << endl;

    //perkalian matriks 3x3
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian matriks 3x3 : \n";
    tampilkanHasil(arrE);
    cout << endl;
}
```
### Output Unguided 1 :

Hasil penjumlahan matriks 3x3 : 
2 7 6 
4 6 7 
14 11 14 

Hasil pengurangan matriks 3x3 : 
0 -3 0 
0 2 3 
-2 3 2 

Hasil perkalian matriks 3x3 : 
29 21 25 
50 38 44 
84 76 80 

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided1.1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided1.2.png)

Unguided 1 adalah contoh implementasi array 2 dimensi untuk melakukan berbagai operasi aritmatika pada matriks berukuran 3x3. Pertama program mendeklarasikan dan menginisiaisasi beberapa variabel array, yaitu arrA dan arrB yg berisi nilai awal, serta arrC, arrD, dan arrE untuk menampung hasil. Setelahnya, program melakukan operasi penjumlahan matriks arrA dan arrB yg hasilnya disimpan pada arrC, lalu dilanjutkan dengan operasi pengurangan yg hasilnya disimpan pada arrD. Terakhir, program melakukan operasi perkalian matriks menggunakan tiga lapis perulangan for dan menyimpan hasilnya pada arrE. Setiap hasil dari ketiga opearsi aritmatika tersebut kemudian ditampilkan ke layar secara berurutan dengan menggunakan procedure tampilkanHasil() yg sama.

### 2. Soal Unguided 2

Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat
menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;

}
int main() {
    int a = 12, b = 15, c = 17;
    int *ptr;
    ptr = &a;

    cout << "Nilai dari a: " << a << endl;
    cout << "Alamat dari a: " << &a << endl;
    cout << "Nilai tersimpan di pointer (alamat a): " << ptr << endl;
    cout << "Nilai yang ditunjuk pointer: " << *ptr << endl;

    tukar(&a, &b, &c);
    cout << "Setelah swap\nnilai dari a = " << a << "\nnilai dari b = " << b << "\nnilai dari c = " << c << endl;
    return 0;
}
```
```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}
int main() {
    int a = 10, b = 20, c = 30;
    int& ref = a;
    cout << "Nilai a: " << a << endl;
    cout << "Alamat a: " << &a << endl;
    cout << "Nilai ref: " << ref << endl;
    cout << "Alamat ref: " << &ref << endl;

    ref = 15;
    cout << "Setelah ref = 15\n";
    cout << "Nilai a: " << a << endl;
    cout << "Nilai ref: " << ref << endl;

    tukar(a, b, c);
    cout << "Setelah swap\nNilai a: " << a << "\nNilai b: " << b << "\nNilai c: " << c << endl;
    return 0;
}
```
### Output Unguided 2 - pointer :

Nilai dari a: 12
Alamat dari a: 0xd2d75ffa84
Nilai tersimpan di pointer (alamat a): 0xd2d75ffa84
Nilai yang ditunjuk pointer: 12
Setelah swap
nilai dari a = 15
nilai dari b = 17
nilai dari c = 12

### Output Unguided 2 - reference : 

Nilai a: 10
Alamat a: 0xc63ebff904
Nilai ref: 10
Alamat ref: 0xc63ebff904
Setelah ref = 15
Nilai a: 15
Nilai ref: 15
Setelah swap
Nilai a: 20
Nilai b: 30
Nilai c: 15

##### Output Unguided 2 - pointer
![Screenshot Output Unguided 2_1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided2-pointer.png)

##### Output Unguided 2 - reference
![Screenshot Output Unguided 2_2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided2-reference.png)

Unguided 2 - pointer adalah program untuk mendemonstrasikan penggunaan pointer untuk menampilkan informasi alamat memori dan menukar tiga nilai secara berulang melalui sebuah prosedur. Pertama, program menunjukkan cara kerja dasar pointer dengan menampilkan nilai dan alamat dari variabel a, lalu membandingkannya dengan alamat yang disimpan oleh pointer ptr. Setelah itu, program memanggil prosedur tukar dengan mengirimkan alamat dari tiga variabel (a, b, c). Prosedur ini kemudian menggunakan pointer untuk menukar nilai ketiga variabel tersebut secara langsung di memorinya, dimana nilai a digantikan b, b digantikan c, dan c digantikan oleh nilai a semula. Hasil akhir dari penukaran nilai ini kemudian ditampilkan ke layar.

Unguided 2 - reference adalah program untuk mendemonstrasikan penggunaan reference sebagai alias variabel dan untuk menukar tiga nilai secara berulang melalui sebuah prosedur. Pertama, program menunjukkan cara kerja reference dengan membuktikan bahwa ref berbagi alamat memori yang sama dengan variabel a, sehingga mengubah nilai ref juga akan mengubah nilai a. Setelah itu, program memanggil prosedur tukar yang menerima argumen by-reference untuk menukar nilai dari tiga variabel (a, b, c) secara langsung. Prosedur ini menukar nilai dimana a digantikan b, b digantikan c, dan c digantikan oleh nilai a semula. Hasil akhir dari penukaran nilai ini kemudian ditampilkan ke layar.

### 3. Soal Unguided 3
Diketahui sebuah array 1 dimensi sebagai berikut :
arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}
Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari
array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan
function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur
hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan
menu switch-case seperti berikut ini :

```C++
#include <iostream>
#include <stdlib.h>
using namespace std;

void tampilkanArray(int arr[], int ukuran){
    for (int i = 0; i < ukuran; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int cariMaksimum(int arr[], int ukuran) {
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > MAX) {
            MAX = arr[i];
        }
    }
    return MAX;
}

int cariMinimum(int arr[], int ukuran) {
    int MIN = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] < MIN) {
            MIN = arr[i];
        }
    }
    return MIN;
}

void rataRata(int arr[], int ukuran) {
    int jumlah = 0;
    float rerata;
    for (int i = 0; i < ukuran; i++) {
        jumlah += arr[i];
    }
    rerata = float(jumlah) / ukuran;
    cout << rerata << endl;
}

int main() {
const int ukuran = 10;
int arrA[ukuran] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
while (true) {
cout << "\n--- Menu Program Array ---\n1. Tampilkan isi array\n2. Cari nilai maksimum\n3. Cari nilai minimum\n4. Hitung nilai rata-rata\n5. Exit\nPilihanmu: ";
int input;
cin >> input;
switch (input) {
    case 1: 
    cout << "Isi array: ";
    tampilkanArray(arrA, ukuran);
    break;
    case 2:
    cout << "Nilai Maksimum: " << cariMaksimum(arrA, ukuran) << endl;
    break;
    case 3: 
    cout << "Nilai Minimum: " << cariMinimum(arrA, ukuran) << endl;
    break;
    case 4:
    cout << "Rata-rata: ";
    rataRata(arrA, ukuran);
    break;
    case 5:
    cout << "Program Ditutup." << endl;
    exit(0);

    default:
    cout << "Invalid! masukkan input yang benar!";
    break;
}

}

}
```
### Output Unguided 3 :
--- Menu Program Array ---
1. Tampilkan isi array
2. Cari nilai maksimum
3. Cari nilai minimum
4. Hitung nilai rata-rata
5. Exit
Pilihanmu: 1
Isi array: 11 8 5 7 12 26 3 54 33 55

--- Menu Program Array ---
1. Tampilkan isi array
2. Cari nilai maksimum
3. Cari nilai minimum
4. Hitung nilai rata-rata
5. Exit
Pilihanmu: 2
Nilai Maksimum: 55

--- Menu Program Array ---
1. Tampilkan isi array
2. Cari nilai maksimum
3. Cari nilai minimum
4. Hitung nilai rata-rata
5. Exit
Pilihanmu: 3
Nilai Minimum: 3

--- Menu Program Array ---
1. Tampilkan isi array
2. Cari nilai maksimum
3. Cari nilai minimum
4. Hitung nilai rata-rata
5. Exit
Pilihanmu: 4
Rata-rata: 21.4

--- Menu Program Array ---
1. Tampilkan isi array
2. Cari nilai maksimum
3. Cari nilai minimum
4. Hitung nilai rata-rata
5. Exit
Pilihanmu: 5
Program Ditutup.
##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided3.1.png)
##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided3.2.png)
##### Output 3
![Screenshot Output Unguided 3_3](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided3.3.png)
##### Output 4
![Screenshot Output Unguided 3_4](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided3.4.png)
##### Output 5
![Screenshot Output Unguided 3_5](https://github.com/marzhendo/103112400102_Marzhendo-Galang-Saputra/blob/main/Pertemuan2_Modul2/Screenshot/Modul2-Unguided3.5.png)

Unguided 3 sebuah implementasi yang membedakan antara func yang mengembalikan return dan procedure yang hanya menjalankan sebuah aksi.

Pertama, program akan meminta pengguna untuk memasukkan 5 buah nilai integer yang akan disimpan ke dalam sebuah array. Setelah semua nilai dimasukkan, program akan memanggil fungsi cariMax(). Fungsi ini bertugas untuk mencari nilai terbesar dari seluruh elemen di dalam array tersebut. Sesuai sifatnya sebagai fungsi, cariMax() akan mengembalikan (return) sebuah nilai integer, yaitu nilai terbesar yang ditemukannya, yang hasilnya kemudian akan ditangkap dan ditampilkan langsung oleh fungsi main.

Kemudian, program memanggil operasiAritmatika(), yang merupakan sebuah prosedur bertipe void. Karena bertipe void, prosedur ini tidak mengembalikan nilai apa pun. Sebaliknya, ia langsung menjalankan serangkaian perintah di dalamnya, yaitu menghitung total penjumlahan dan total perkalian dari seluruh elemen array, lalu menampilkan kedua hasil tersebut langsung ke layar.

## Kesimpulan
Kesimpulan dari latihan unguided ini adalah agar mahasiswa lebih terbiasa dengan sintaks sintaks yang ada di c++ serta mengasah logic dan problem solving mahasiswa.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

