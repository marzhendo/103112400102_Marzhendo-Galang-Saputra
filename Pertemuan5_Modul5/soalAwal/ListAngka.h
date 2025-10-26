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

#endif