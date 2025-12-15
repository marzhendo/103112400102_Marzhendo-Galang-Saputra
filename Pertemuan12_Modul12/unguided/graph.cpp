#include "graph.h"
#include <queue>
#include <stack>

void CreateGraph(Graph &G) {
    G.First = NULL;
}

adrNode AlokasiNode(infoGraph data) {
    adrNode newNode = new ElmNode;
    newNode->info = data;
    newNode->visited = 0;
    newNode->firstEdge = NULL;
    newNode->Next = NULL;
    return newNode;
}

adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge newEdge = new ElmEdge;
    newEdge->Node = nodeTujuan;
    newEdge->Next = NULL;
    return newEdge;
}

void InsertNode(Graph &G, infoGraph data) {
    adrNode newNode = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = newNode;
    } else {
        adrNode P = G.First;
        while (P->Next != NULL) {
            P = P->Next;
        }
        P->Next = newNode;
    }
}

adrNode FindNode(Graph G, infoGraph data) {
    adrNode P = G.First;
    while (P != NULL) {
        if (P->info == data) {
            return P;
        }
        P = P->Next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        adrEdge edge1 = AlokasiEdge(node2);
        edge1->Next = node1->firstEdge;
        node1->firstEdge = edge1;

        adrEdge edge2 = AlokasiEdge(node1);
        edge2->Next = node2->firstEdge;
        node2->firstEdge = edge2;
    }
}

void ResetVisited(Graph &G) {
    adrNode P = G.First;
    while (P != NULL) {
        P->visited = 0;
        P = P->Next;
    }
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.First;
    while (P != NULL) {
        cout << "Node " << P->info << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    ResetVisited(G);
    
    if (N == NULL) {
        return;
    }

    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrNode currNode = Q.front();
        Q.pop();
        cout << currNode->info << " ";

        adrEdge E = currNode->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
    cout << endl;
}

void PrintDFS(Graph G, adrNode N) {
    ResetVisited(G);

    if (N == NULL) {
        return;
    }

    stack<adrNode> S;
    S.push(N);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrNode currNode = S.top();
        S.pop();

        if (currNode->visited == 0) {
            currNode->visited = 1;
            cout << currNode->info << " ";

            adrEdge E = currNode->firstEdge;
            while (E != NULL) {
                if (E->Node->visited == 0) {
                    S.push(E->Node);
                }
                E = E->Next;
            }
        }
    }
    cout << endl;
}