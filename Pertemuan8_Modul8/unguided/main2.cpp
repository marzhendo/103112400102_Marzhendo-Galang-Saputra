#include "queue.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    
    cout<<"-------------------"<<endl;
    cout<<" H  T | Queue info"<<endl;
    cout<<"-------------------"<<endl;

    CreateQueue(Q);
    printInfo(Q);

    cout << "== Mengisi Penuh Queue ==" << endl;
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);
    printInfo(Q);

    cout << "== Dequeue 2x (Menciptakan 'Penuh Sementara') ==" << endl;
    dequeue(Q);
    dequeue(Q);
    printInfo(Q);

    cout << "== Enqueue 2x (Memicu Perbedaan Logika) ==" << endl;
    enqueue(Q, 6);
    printInfo(Q);
    
    enqueue(Q, 7);
    printInfo(Q);

    cout << "== Mengosongkan Queue ==" << endl;
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);

    return 0;
}