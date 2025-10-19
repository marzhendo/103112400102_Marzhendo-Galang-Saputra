#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    deleteFirst(L, P5);
    dealokasi(P5);

    deleteLast(L, P1);
    dealokasi(P1);

    deleteAfter(L, P3, P4);
    dealokasi(P3);

    printInfo(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);

    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}