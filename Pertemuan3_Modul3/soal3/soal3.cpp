#include <iostream>
#include <iomanip>

using namespace std;

void tampilArray(const int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
}

void tukarElemenArray(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int arrayA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arrayB[3][3] = {{99, 88, 77}, {66, 55, 44}, {33, 22, 11}};
    int nilaiX = 100;
    int nilaiY = 200;
    int *pointerX = &nilaiX;
    int *pointerY = &nilaiY;

    cout << "Array A Awal:" << endl;
    tampilArray(arrayA);
    cout << "\nArray B Awal:" << endl;
    tampilArray(arrayB);

    tukarElemenArray(arrayA, arrayB, 1, 1);

    cout << "\nArray A Setelah Tukar [1][1]:" << endl;
    tampilArray(arrayA);
    cout << "\nArray B Setelah Tukar [1][1]:" << endl;
    tampilArray(arrayB);

    cout << "\nNilai Awal -> X: " << *pointerX << ", Y: " << *pointerY << endl;
    tukarPointer(pointerX, pointerY);
    cout << "Nilai Akhir -> X: " << *pointerX << ", Y: " << *pointerY << endl;

}