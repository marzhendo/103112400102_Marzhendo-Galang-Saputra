#include "Doublylist.h"
#include <string>

int main() {
    List L;
    CreateList(L);
    
    infotype data;
    address P;

    // ======================================================
    // BAGIAN SOAL 1: MEMASUKKAN DATA
    // ======================================================

    // --- Input 1 (D001) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore(); 
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;

    // --- Input 2 (D003) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore();
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;

    // --- Input 3 (D001 - Duplikat) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore();
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;

    // --- Input 4 (D004) ---
    cout << "masukkan nomor polisi: ";
    getline(cin, data.nopol);
    cout << "masukkan warna kendaraan: ";
    getline(cin, data.warna);
    cout << "masukkan tahun kendaraan: ";
    cin >> data.thnBuat;
    cin.ignore();
    
    if (findNopol(L, data.nopol)) {
        cout << "nomor polisi sudah terdaftar" << endl;
    } else {
        P = alokasi(data);
        insertLast(L, P);
    }
    cout << endl;
    
    // --- Menampilkan Hasil Soal 1 ---
    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;
    
    // ======================================================
    // BAGIAN SOAL 2: MENCARI DATA
    // ======================================================
    
    infotype dataCari;
    address hasilCari;
    
    cout << "Masukkan Nomor Polisi yang dicari : ";
    getline(cin, dataCari.nopol);
    
    hasilCari = findElm(L, dataCari);
    
    if (hasilCari != Nil) {
        cout << endl;
        cout << "Nomor Polisi : " << hasilCari->info.nopol << endl;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Nomor polisi " << dataCari.nopol << " tidak ditemukan." << endl;
    }

    // ======================================================
    // BAGIAN SOAL 3: MENGHAPUS DATA
    // ======================================================
    
    string nopolHapus;
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    getline(cin, nopolHapus);
    
    deleteDataByNopol(L, nopolHapus);
    
    cout << endl << "DATA LIST 1" << endl;
    printInfo(L);
    
    return 0;
}