#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    const int MAX_MAHASISWA = 10;
    Mahasiswa daftarMhs[MAX_MAHASISWA];
    int jumlahMhs = 0;
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> jumlahMhs;
    cin.ignore();

    if (jumlahMhs > MAX_MAHASISWA) {
        jumlahMhs = MAX_MAHASISWA;
    }

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nInput Mahasiswa ke-" << i + 1 << ":\n";
        inputMahasiswa(daftarMhs[i]);
        hitungNilaiAkhir(daftarMhs[i]);
    }

    cout << "\nData Hasil Inputan\n";
    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nData ke-" << i+1 << ":\n";
        tampilMahasiswa(daftarMhs[i]);
    }
}