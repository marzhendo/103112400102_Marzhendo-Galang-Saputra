#ifndef QUEUEPENGIRIMAN_H
#define QUEUEPENGIRIMAN_H
#define Nill NULL
#include <iostream>
using namespace std;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

typedef Paket dataPaket;
typedef struct node *address;

const int MAX = 5;

struct QueueEkspedisi {
    dataPaket info[MAX];
    int head;
    int tail;
};

bool isEmpty(QueueEkspedisi Q);
bool isFull(QueueEkspedisi Q);
void createQueue(QueueEkspedisi &Q);
void enqueue(QueueEkspedisi &Q, dataPaket dataBaru);
dataPaket dequeue(QueueEkspedisi &Q);
void viewQueue(QueueEkspedisi Q);
void totalBiayaPengiriman(QueueEkspedisi Q); //BAGIAN B
#endif