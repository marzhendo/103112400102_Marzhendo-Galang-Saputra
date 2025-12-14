#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'D', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== TRAVERSAL ===" << endl;
    cout << "BFS Traversal: ";
    PrintBFS(G, 'A');
    cout << endl;
    cout << "DFS Traversal: ";
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== DELETE NODE ===" << endl;
    DeleteNode(G, 'E');
    if (FindNode(G, 'E') == NULL) {
        cout << "Node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak ditemukan" << endl;
    }
    cout << endl;
    
    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    cout << "BFS Traversal: ";
    PrintBFS(G, 'A');
    cout << endl;
    cout << "DFS Traversal: ";
    PrintDFS(G, 'A');
    cout << endl;

    return 0;
}
