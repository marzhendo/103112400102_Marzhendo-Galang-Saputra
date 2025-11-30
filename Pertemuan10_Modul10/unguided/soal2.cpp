// main_soal2.cpp
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    // kode ini bagian soal no 2 (tree sama dengan soal 1)
    address root = Nil;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 6);
    insertNode(root, 7);

    printInOrder(root);
    cout << endl;

    cout << "kedalaman : "   << hitungKedalaman(root)    << endl;
    cout << "jumlah node : " << hitungJumlahNode(root)   << endl;
    cout << "total : "       << hitungTotal(root)        << endl;

    return 0;
}
