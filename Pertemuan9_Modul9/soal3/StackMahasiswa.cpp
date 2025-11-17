#include "StackMahasiswa.h"
#include <iostream>
using namespace std;

bool isEmpty(StackMahasiswa S) {
    return S.top == -1;
}

bool isFull(StackMahasiswa S) {
    return S.top == MAX - 1;
}

void createStack(StackMahasiswa &S) {
    S.top = -1;
}

void push(StackMahasiswa &S, dataMahasiswa dataBaru) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = dataBaru;
    } else {
        cout << "Stack penuh, tidak dapat menambahkan data baru." << endl;
    }
}

dataMahasiswa pop(StackMahasiswa &S) {
    if (!isEmpty(S)) {
        dataMahasiswa dataKeluar = S.info[S.top];
        S.top--;
        return dataKeluar;
    } else {
        cout << "Stack kosong, tidak ada data yang dapat dihapus." << endl;
        return {"", "", 0.0, 0.0, 0.0}; // Return empty data
    }
}

void update(StackMahasiswa &S, int posisi, dataMahasiswa dataBaru) {
    if (posisi >= 0 && posisi <= S.top) {
        S.info[posisi] = dataBaru;
    } else {
        cout << "Posisi tidak valid." << endl;
    }
}

void view(StackMahasiswa S) {
    if (!isEmpty(S)) {
        for (int i = 0; i <= S.top; i++) {
            cout << "Mahasiswa ke-" << i + 1 << ":" << endl;
            cout << "Nama: " << S.info[i].Nama << endl;
            cout << "NIM: " << S.info[i].NIM << endl;
            cout << "Nilai Tugas: " << S.info[i].NilaiTugas << endl;
            cout << "Nilai UTS: " << S.info[i].NilaiUTS << endl;
            cout << "Nilai UAS: " << S.info[i].NilaiUAS << endl;
            cout << "------------------------" << endl;
        }
    } else {
        cout << "Stack kosong." << endl;
    }
}

void searchNilaiAkhir(StackMahasiswa S, float nilaiAkhirMin, float nilaiAkhirMax) {
    if (!isEmpty(S)) {
        bool found = false;
        for (int i = 0; i <= S.top; i++) {
            float nilaiAkhir = 0.2 * S.info[i].NilaiTugas + 0.4 * S.info[i].NilaiUTS + 0.4 * S.info[i].NilaiUAS;
            if (nilaiAkhir >= nilaiAkhirMin && nilaiAkhir <= nilaiAkhirMax) {
                cout << "Mahasiswa ditemukan dengan nilai akhir dalam rentang:" << endl;
                cout << "Nama: " << S.info[i].Nama << endl;
                cout << "NIM: " << S.info[i].NIM << endl;
                cout << "Nilai Tugas: " << S.info[i].NilaiTugas << endl;
                cout << "Nilai UTS: " << S.info[i].NilaiUTS << endl;
                cout << "Nilai UAS: " << S.info[i].NilaiUAS << endl;
                cout << "Nilai Akhir: " << nilaiAkhir << endl;
                cout << "------------------------" << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Tidak ada mahasiswa dengan nilai akhir dalam rentang yang ditentukan." << endl;
        }
    } else {
        cout << "Stack kosong." << endl;
    }
}

void maxNilaiAkhir(StackMahasiswa S) {
    if (!isEmpty(S)) {
        float maxNilaiAkhir = -1.0;
        int posisiMax = -1;
        for (int i = 0; i <= S.top; i++) {
            float nilaiAkhir = 0.2 * S.info[i].NilaiTugas + 0.4 * S.info[i].NilaiUTS + 0.4 * S.info[i].NilaiUAS;
            if (nilaiAkhir > maxNilaiAkhir) {
                maxNilaiAkhir = nilaiAkhir;
                posisiMax = i;
            }
        }
        if (posisiMax != -1) {
            cout << "Mahasiswa dengan nilai akhir tertinggi:" << endl;
            cout << "Nama: " << S.info[posisiMax].Nama << endl;
            cout << "NIM: " << S.info[posisiMax].NIM << endl;
            cout << "Nilai Tugas: " << S.info[posisiMax].NilaiTugas << endl;
            cout << "Nilai UTS: " << S.info[posisiMax].NilaiUTS << endl;
            cout << "Nilai UAS: " << S.info[posisiMax].NilaiUAS << endl;
            cout << "Nilai Akhir: " << maxNilaiAkhir << endl;
        }
    } else {
        cout << "Stack kosong." << endl;
    }
}
