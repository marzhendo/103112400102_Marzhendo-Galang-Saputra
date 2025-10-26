#ifndef LISTANGKA_H
#define LISTANGKA_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka Angka;
    address Next;
};

struct linkedList {
    address First;
};

bool isEmpty(linkedList L);
void CreateList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &node);
void printList(linkedList L);
void insertFirst(linkedList &L, address nodeBaru);
void insertLast(linkedList &L, address nodeBaru);
void insertAfter(linkedList &L, address nodeBaru, address nodePrev);
int nbList(linkedList L);
void delAfter(linkedList &L, address nodeHapus, address nodePrev);

void updateFirst(linkedList &L);
void updateLast(linkedList &L);
void updateAfter(linkedList &L, address nodePrev);

void SearchByData(linkedList L, dataAngka data);
void SearchByAddress(linkedList L, address node);
void SearchByRange(linkedList L, dataAngka nilaiMin);

#endif