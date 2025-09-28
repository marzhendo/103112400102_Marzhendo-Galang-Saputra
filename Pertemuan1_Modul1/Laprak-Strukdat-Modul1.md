# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
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
    cout << "Hallo Dunia";
    return 0;
}
```
Guided 1 adalah contoh cara mencetak dengan cpp yaitu dengan menggunakan cout << "kalimat"; dengan begitu kalimat yang kita inginkan akan tercetak, jangan lupa setiap baris code harus diakhiri dengan semi colon ; agar tidak terjadi eror, kecuali pada baris kondisi.

### 2. Guided 2

```C++
#include <iostream>

using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka1: ";
    cin >> angka1;
    cout << "Masukkan angka2: ";
    cin >> angka2;

    for (int i = 0; i < angka1; i++) {
        cout << i << " - ";
    }

    cout << endl;

    for (int i = 20; i > angka2; i--) {
        cout << i << " - ";
    }

    cout << endl;
}
```
Guided 2 adalah contoh perulangan dalam c++. program meminta 2 inputan untuk inputan pertama, program akan melakukan perulangan dari 0 sampai angka sebelum inputan dan diantara angka akan dicetak juga " - ".
contoh angka1 = 5
       output = 0 - 1 - 2 - 3 - 4 - 
untuk perulangan kedua tidak jauh beda, hanya saja perulangan akan dimulai terbalik, dari 20 mundur ke angka sesudah inputan.
contoh angka2 = 15
       output = 20 - 19 - 18 - 17 - 16 -

### 3. Guided 3

```C++
#include <iostream>

using namespace std;

int main() {
    const int jumlah = 5;

    struct raport {
        char nama[5];
        int nilai;
    };

    raport siswa[jumlah] = {};

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan nama siswa: ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai siswa: ";
        cin >> siswa[i].nilai;
    }

    cout << "\n--- Data Siswa ---" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama siswa: " << siswa[i].nama << ", Nilai: " << siswa[i].nilai << endl;
    }

    return 0;
}
```
Guided 3 adalah contoh penggunaan struct yang digabungkan dengan array untuk mengelola data siswa. Pertama, program akan melakukan perulangan untuk meminta input data. Program akan meminta nama dan nilai siswa sebanyak 5 kali sesuai dengan nilai konstanta jumlah. Setiap data yang dimasukkan akan disimpan dalam array siswa. Setelah semua data dimasukkan, program akan masuk ke perulangan kedua. Perulangan ini tidak jauh beda, hanya saja fungsinya untuk menampilkan kembali semua data yang sudah tersimpan di dalam array.

## Unguided 

### 1. Soal Unguided 1

Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

```C++
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    float a1, a2;
    float penjumlahan, pengurangan, perkalian, pembagian;
    cout << "Masukkan angka pertama: ";
    cin >> a1;
    cout << "Masukkan angka kedua: ";
    cin >> a2;
    penjumlahan = a1 + a2;
    pengurangan = a1 - a2;
    perkalian = a1 * a2;
    pembagian = a1 / a2;
    printf("Hasil penjumlahan adalah %.1f\n", penjumlahan);
    printf("Hasil pengurangan adalah %.1f\n", pengurangan);
    printf("Hasil perkalian adalah %.1f\n", perkalian);
    printf("Hasil pembagian adalah %.1f\n", pembagian);
    return 0;
}
```
### Output Unguided 1 :

Masukkan angka pertama: 50
Masukkan angka kedua: 10
Hasil penjumlahan adalah 60.0
Hasil pengurangan adalah 40.0
Hasil perkalian adalah 500.0
Hasil pembagian adalah 5.0

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Unguided 1 adalah program untuk melakukan operasi aritmatika dasar seperti (+, -, *, /),
user diminta menginput 2 angka melalui variabel a1, dan a2. Lalu library <stdio.h> digunakan agar dapat menggunakan printf supaya output bisa desimal dibelakang angka.

### 2. Soal Unguided 2

Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100

```C++
#include <iostream>
#include <string>

using namespace std;

string angkaKeTulisan(int angka) {
    if (angka < 0 || angka > 100) {
        return "Error! Batas inputan adalah 0 - 100.";
    }

    const string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat", "lima", "enam",
        "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"
    };

    if (angka <= 11) {
        return satuan[angka];
    } else if (angka < 20) {
        return satuan[angka % 10] + " belas";
    } else if (angka < 100) {
        string hasil = satuan[angka / 10] + " puluh";
        if (angka % 10 != 0) {
            hasil += " " + satuan[angka % 10];
        }
        return hasil;
    } else {
        return "seratus";
    }
}
int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;
    string tulisan = angkaKeTulisan(angka);
    cout << "Hasil konversi: " << tulisan;
    return 0;
}
```
### Output Unguided 2 :

Input angka (0-100): 79
Hasil setelah diubah: tujuh puluh sembilan

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Unguided 2 adalah program untuk mengubah nilai integer ke string. Program ini meminta inputan dalam rentang 0 - 100 dan mengkonversinya jadi string menggunakan func angkaKeTulisan. fungsi bekerja dengan 5 kondisi yang berbeda. kondisi pertama memeriksa angka apakah angka dalam rentang 0 - 100? jika iya maka kondisi ini akan diabaikan, jika tidak maka akan mengeksekusi ""Error! Batas inputan adalah 0 - 100.".  kondisi kedua akan memeriksa apakah angka dalam rentang 0 - 11, jika iya maka akan langsung return value dari array menyesuaikan satuan sesuai index angka tersebut. kondisi ketiga untuk angka 12-19. logic % 10 akan mengambil digit terakhir dari angka dan menjadikan digit tersebut untuk mengakses value di dalam array. misal 13 % 10 = 1 sisa 3. angka 3 ini akan diambil untuk mengakses array index ke 3 dan setelah dapat valuenya nantinya akan ditambah string " belas". kondisi keempat untuk angka 20 - 99, operator / digunakan untuk mengambil digit awal, dan operator % digunakan untuk mengambil digit akhir. untuk operator % akan tereksekusi dengan kondisi jika digit yang dimodulus tidak habis atau != 0. misal 58 akan return "lima puluh delapan" karena 58/10=5 menghasilkan "lima puluh" dan 58 % 10 = 8 menambahkan "delapan". kondisi terakhir untuk angka 100 akan mereturn "seratus".

### 3. (isi dengan soal unguided 3)

```C++
#include <iostream>

using namespace std;

void pola(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < (n - i); j++) {
            cout << " ";
        }
        for (int k = i; k >= 1; k--) {
            cout << k;
        }
        cout << " * ";

         for (int k = 1; k <= i; k++){
            cout << k;
        }
        cout << endl;
    }
    for (int k = 0; k < (n-1); k++) {
        cout << " ";
    }
    cout << "  *" << endl;
}

int main() {
    int n;
    cout << "Masukkan input: ";
    cin >> n;
    cout << "Output: " << endl;
    pola(n);
}
```
### Output Unguided 3 :
Masukkan input: 6
Output: 
654321 * 123456
 54321 * 12345
  4321 * 1234
   321 * 123
    21 * 12
     1 * 1
       *
##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

Unguided 3 adalah program yang berfungsi untuk mencetak pola piramida tapi terbalik. Polanya terdiri dari dua bagian angka yang dicetak simetris, dipisahkan dengan tanda *, dan diakhiri dengan satu tanda * di baris terakhir. Pola ini dimulai dari angka n(input), dan menurun hingga 1 di setiap baris, dengan tambahan spasi yang bertambah di awal setiap baris baru.

## Kesimpulan
Kesimpulan dari latihan unguided ini adalah agar mahasiswa lebih terbiasa dengan sintaks sintaks yang ada di c++ serta mengasah logic dan problem solving mahasiswa.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 

