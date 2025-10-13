#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMahasiswa(Mahasiswa &m) {
    cout << "Nama: ";
    getline(cin, m.nama);
    cout << "NIM: ";
    cin >> m.nim;
    cout << "UTS: ";
    cin >> m.uts;
    cout << "UAS: ";
    cin >> m.uas;
    cout << "Tugas: ";
    cin >> m.tugas;
    cin.ignore();
}

void hitungNilaiAkhir(Mahasiswa &m) {
    m.nilaiAkhir = (0.3 * m.uts) + (0.4 * m.uas) + (0.3 * m.tugas);
}

void tampilMahasiswa(const Mahasiswa &m) {
    cout << "Nama: " << m.nama << "\n";
    cout << "NIM: " << m.nim << "\n";
    cout << "Nilai Akhir: " << m.nilaiAkhir <<  "\n";
}