#include <iostream>
#include <string>

using namespace std;

string angkaKeTulisan(int angka) {
    if (angka < 0 || angka > 100) {
        return "Error! Batas inputan adalah 0 - 100.";
    }

    const string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat", "lima", "enam",
        "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"
    };

    if (angka <= 11) {
        return satuan[angka];
    } else if (angka < 20) {
        return satuan[angka % 10] + " belas";
    } else if (angka < 100) {
        string hasil = satuan[angka / 10] + " puluh";
        if (angka % 10 != 0) {
            hasil += " " + satuan[angka % 10];
        }
        return hasil;
    } else {
        return "seratus";
    }
}
int main() {
    int angka;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;
    string tulisan = angkaKeTulisan(angka);
    cout << "Hasil konversi: " << tulisan;
    return 0;
}
