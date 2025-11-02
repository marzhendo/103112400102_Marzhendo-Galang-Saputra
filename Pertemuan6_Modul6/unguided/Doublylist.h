#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL
#include <iostream>
#include <string>
using namespace std;

struct kenderaan {
    string nopol;
    string warna;
    int thnBuat;
};

typedef kenderaan infotype;

typedef struct ElmtList *address;

struct ElmtList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);

address findElm(List L, infotype x);

bool findNopol(List L, string nopol);

address findElmByNopol(List L, string nopol);
void deleteDataByNopol(List &L, string nopol);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);

#endif