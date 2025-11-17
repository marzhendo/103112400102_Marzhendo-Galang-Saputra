#include "DLLPlaylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L); //soal 1 buat list kosong
    address S1, S2, S3; //soal 2 masukan 3 lagu dengan insert last
    S1 = allocate("Senja di Kota", "Nona Band", 210, 150, 4.2);
    insertLast(L, S1);
    S2 = allocate("Langkahmu", "Delta", 185, 320, 4.8);
    insertLast(L, S2);
    S3 = allocate("Hujan Minggu", "Arka", 240, 90, 3.9);
    insertLast(L, S3);
    cout << "Daftar Lagu Setelah Insert Last:" << endl;
    viewList(L);        //soal 3 tampilkan list
    cout << endl;
    deleteLast(L, S3);       //soal 4 lakukan delete last 1x
    updateAtPosition(L, 1, {"Pelita", "Luna", 200, 260, 4.5} );       //soal 5 update node pada posisi 2
    cout << "Daftar Lagu Setelah Delete Last dan Update lagu posisi 2:" << endl;
    viewList(L);    //soal 6 tampilkan list
    cout << endl;

    // soal 7 operasi before
    //insert before node posisi 2
    address S4;
    S4 = allocate("Senandung", "Mira", 175, 120, 4.0);
    insertBefore(L, S4, S2);
    cout << "Daftar Lagu Setelah Insert Before lagu posisi 2:" << endl;
    viewList(L);
    cout << endl;
    //update before node posisi 2
    updateBefore(L, S2, {"JANE DOE", "Kenshi Yonezu", 190, 300, 4.9});
    cout << "Daftar Lagu Setelah Update Before lagu posisi 2:" << endl;
    viewList(L);
    cout << endl;
    //delete before node posisi 3
    address S5;
    deleteBefore(L, S5, S2);
    cout << "Daftar Lagu Setelah Delete Before lagu posisi 3:" << endl;
    viewList(L);
    cout << endl;
    // soal 8 search by popularity range
    searchByPopularityRange(L, 1.5, 3.0);
    return 0;
}   