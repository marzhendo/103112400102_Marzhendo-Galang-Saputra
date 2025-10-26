#include "listAngka.h"
#include <iostream>

using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;
    CreateList(List);

    nodeA = alokasi(8);
    nodeB = alokasi(13);
    nodeC = alokasi(18);
    nodeD = alokasi(25);
    nodeE = alokasi(33);
    nodeF = alokasi(40);

    insertFirst(List, nodeB);
    insertLast(List, nodeA);
    insertAfter(List, nodeD, nodeB);
    insertFirst(List, nodeC);
    insertLast(List, nodeE);
    insertFirst(List, nodeF);

    delAfter(List, nodeB, nodeC);

    printList(List);
    cout << endl;

    updateFirst(List);
    updateAfter(List, nodeD);
    updateLast(List);
    updateAfter(List, nodeF);

    printList(List);
    cout << endl;

    SearchByData(List, 20);
    SearchByData(List, 55);
    SearchByAddress(List, nodeB);
    SearchByAddress(List, nodeA);
    SearchByRange(List, 40);
    cout << endl;

   int sum = 0;
    int subtraction = 0; 
    long long multiplication = 1;
    bool firstNode = true;
    address nodeBantu = List.First;

    while (nodeBantu != Nil) {
        sum += nodeBantu->Angka;
        multiplication *= nodeBantu->Angka;

        if (firstNode) {
            
            firstNode = false;
        } else {
            
            subtraction -= nodeBantu->Angka;
        }
        nodeBantu = nodeBantu->Next;
    }

    cout << "Total penjumlahan : " << sum << endl;
    cout << "Total pengurangan : " << subtraction << endl;
    cout << "Total perkalian : " << multiplication << endl;
    cout << endl;


    return 0;
}