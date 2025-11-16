#ifndef QUEUE_H
#define QUEUE_H
#define NIL NULL
using namespace std;
#include <string>

struct Node {
    std::string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void CreateQueue(queue& Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue& Q, const string& nama);
void deQueue(queue& Q);
void viewQueue(queue Q);
void clearQueue(queue& Q);

#endif
