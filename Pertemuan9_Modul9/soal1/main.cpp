#include "SLLInventory.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3;
    createList(L);

    P1 = allocate("Pulpen", "A001", 20, 2500.0, 0);
    insertLast(L, P1);
    P2 = allocate("Buku Tulis", "A002", 15, 5000.0, 10);
    insertLast(L, P2);
    P3 = allocate("Penghapus", "A003", 30, 1500.0, 0);
    insertLast(L, P3);
    cout << "Daftar Produk Setelah Insert Last:" << endl;
    viewList(L);
    cout << endl;
    deleteFirst(L, P1);
    cout << "Daftar Produk Setelah Delete First:" << endl;
    viewList(L);
    cout << endl;
    updateAtPosition(L, 0, {"Stabillo", "A010", 40, 9000.0, 5.0});
    cout << "Daftar Produk Setelah Update at Position 0:" << endl;
    viewList(L);
    cout << endl;
    searchByFinalPriceRange(L, 2000.0, 7000.0);
    cout << endl;
    maxHargaAkhir(L); // BAGIAN B
    return 0;
}