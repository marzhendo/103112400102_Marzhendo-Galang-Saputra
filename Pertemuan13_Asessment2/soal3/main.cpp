#include "graphKota.h"

int main() {
    //bagian A
    GraphKota G;
    createGraph(G);

    // 1. Insert Node and connect node
    insertNode(G, alokasiNode("Jakarta"));
    insertNode(G, alokasiNode("Bogor"));
    insertNode(G, alokasiNode("Depok"));
    insertNode(G, alokasiNode("Tangerang"));
    insertNode(G, alokasiNode("Bekasi"));

    connectNode(G, "Jakarta", "Bogor", 42);
    connectNode(G, "Jakarta", "Bekasi", 16);
    connectNode(G, "Jakarta", "Depok", 21);
    connectNode(G, "Jakarta", "Tangerang", 24);

    connectNode(G, "Bogor", "Jakarta", 42);
    connectNode(G, "Bogor", "Depok", 22);
    connectNode(G, "Bogor", "Bekasi", 60);

    connectNode(G, "Depok", "Jakarta", 21);
    connectNode(G, "Depok", "Bogor", 22);
    connectNode(G, "Depok", "Tangerang", 30);
    connectNode(G, "Depok", "Bekasi", 25);
;
    connectNode(G, "Tangerang", "Bekasi", 45);
    connectNode(G, "Tangerang", "Depok", 30);

    connectNode(G, "Bekasi", "Jakarta", 16);
    connectNode(G, "Bekasi", "Bogor", 60);
    connectNode(G, "Bekasi", "Tangerang", 45);
    connectNode(G, "Bekasi", "Depok", 25);

    // 2. Print Graph Awal
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    printGraph(G);
    cout << endl;

    // 3. Delete Node Depok
    cout << "=== SETELAH DELETE NODE DEPOK ===" << endl;
    deleteNode(G, "Depok");
    // 4. Print Graph
    printGraph(G);

    // Bagian B
    cout << "\n=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");

    return 0;
}