#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#define Nill NULL
#include <iostream>
using namespace std;

struct Song {
    string Tittle;
    string Artist;
    int DurationSec;
    int PlayCount;
    float Rating;
};

typedef Song dataSong;
typedef struct Node *address;

struct Node {
    Song info;
    address next;
    address prev;
};

struct List {
    address head;
    address tail;
};

bool isEmpty(List List);
void createList(List &List);
address allocate(string tittle, string artist, int durationSec, int playCount, float rating);
void deallocate(address &Node);
void insertFirst(List &List, address nodeBaru);
void insertAfter(List &List, address nodeBaru, address Prev);
void insertLast(List &List, address nodeBaru);
void insertBefore(List &List, address nodeBaru, address Succ);
void deleteFirst(List &List, address &nodeHapus);
void deleteAfter(List &List, address &nodeHapus, address Prev);
void deleteLast(List &List, address &nodeHapus);
void deleteBefore(List &List, address &nodeHapus, address Succ);
void updateAtPosition(List &List, int posisi, Song dataBaru);
void updateBefore(List &List, address Succ, Song dataBaru);
void viewList(List List);
void searchByPopularityRange(List List, float minScore, float maxScore);

#endif
