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
        {1, 2, 3},
        {2, 8, 2},
        {4, 4, 6}
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