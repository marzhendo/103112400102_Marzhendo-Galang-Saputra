#include "queue.h"

void CreateQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    if (isEmptyQueue(Q)) {
        return false;
    }
    int next_tail = (Q.tail + 1) % MAX_QUEUE;
    return next_tail == Q.head;
}

void enqueue(Queue &Q, infotype x) {
    if (!isFullQueue(Q)) {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX_QUEUE;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x = -1;
    if (!isEmptyQueue(Q)) {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            CreateQueue(Q);
        } else {
            Q.head = (Q.head + 1) % MAX_QUEUE;
        }
    }
    return x;
}

void printInfo(Queue Q) {
    cout << setw(3) << Q.head << setw(3) << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        if (Q.head <= Q.tail) {
            for (int i = Q.head; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        } else {
            for (int i = Q.head; i < MAX_QUEUE; i++) {
                cout << Q.info[i] << " ";
            }
            for (int i = 0; i <= Q.tail; i++) {
                cout << Q.info[i] << " ";
            }
        }
    }
    cout << endl;
}