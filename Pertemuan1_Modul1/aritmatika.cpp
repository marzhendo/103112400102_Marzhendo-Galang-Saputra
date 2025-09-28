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
