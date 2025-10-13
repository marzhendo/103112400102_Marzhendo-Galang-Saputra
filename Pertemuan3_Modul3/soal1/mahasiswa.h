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