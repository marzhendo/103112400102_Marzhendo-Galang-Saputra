#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

int main() {
    StackMahasiswa S;
    createStack(S); //Soal 1 buat stack kosong
    dataMahasiswa M1, M2, M3, M4, M5, M6; //Soal 2 masukan 6 mahasiswa dengan push
    M1 = {"Venti", "11111", 75.7, 82.1, 65.5};
    M2 = {"Xiao", "22222", 87.4, 88.9, 81.9};
    M3 = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    M4 = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    M5 = {"Lynette", "55555", 77.7, 65.4, 79.9};
    M6 = {"Chasca", "66666", 99.9, 93.6, 87.3};
    push(S, M1);
    push(S, M2);
    push(S, M3);
    push(S, M4);
    push(S, M5);
    push(S, M6);
    cout << "Daftar Mahasiswa Setelah Push" << endl;
    view(S); //soal3 tampilkan stack yang sudah diinputkan data mahasiswa
    cout << endl;

    dataMahasiswa removedStudent = pop(S); //soal4 lakukan pop 1x
    cout << "Mahasiswa yang di-pop:" << endl; //soal 5 tampilkan data mahasiswa yang di pop
    cout << "Nama: " << removedStudent.Nama << endl;
    cout << "NIM: " << removedStudent.NIM << endl;
    cout << "Nilai Tugas: " << removedStudent.NilaiTugas << endl;
    cout << "Nilai UTS: " << removedStudent.NilaiUTS << endl;
    cout << "Nilai UAS: " << removedStudent.NilaiUAS << endl;
    cout << endl;

    //soal 6 update data mahsiswa pada posisi 3
    update(S, 2, {"Heizou", "77777", 99.9, 88.8, 77.7});
    cout << "Daftar Mahasiswa Setelah Update pada posisi 3:" << endl;
    view(S); //soal 7 tampilkan stack yang sudah diupdate
    cout << endl;

    /*soal 8 search data mahasiswa berdasarkan nilai akhir dalam rentang 85.5 sampai 95.5,
    tampilkan pula posisi data ditemukan pada posisi keberapa */
    searchNilaiAkhir(S, 85.5, 95.5);

    //bagian B
    maxNilaiAkhir(S); //soal b tampilkan data mahasiswa dengan nilai akhir tertinggi
    return 0;
}