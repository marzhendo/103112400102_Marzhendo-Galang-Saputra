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