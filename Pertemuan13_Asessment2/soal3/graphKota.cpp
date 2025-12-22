#include "graphKota.h"
#include <queue>
#include <stack>

void createGraph(GraphKota &G) {
    G.First = nullptr;
}

adrKota alokasiNode(string namaKota) {
    adrKota P = new ElmKota;
    P->namaKota = namaKota;
    P->visited = 0;
    P->firstEdge = nullptr;
    P->next = nullptr;
    return P;
}

adrEdge alokasiEdge(adrKota kotaTujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->kotaTujuan = kotaTujuan;
    E->jarak = jarak;
    E->next = nullptr;
    return E;
}

void insertNode(GraphKota &G, adrKota nodeKota) {
    if (G.First == nullptr) {
        G.First = nodeKota;
    } else {
        adrKota P = G.First;
        while (P->next != nullptr) {
            P = P->next;
        }
        P->next = nodeKota;
    }
}

adrKota findNode(GraphKota G, string namaKota) {
    adrKota P = G.First;
    while (P != nullptr) {
        if (P->namaKota == namaKota) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void connectNode(GraphKota &G, string namaKota1, string namaKota2, int jarak) {
    adrKota kota1 = findNode(G, namaKota1);
    adrKota kota2 = findNode(G, namaKota2);
    if (kota1 != nullptr && kota2 != nullptr) {
        adrEdge E = alokasiEdge(kota2, jarak);
        E->next = kota1->firstEdge;
        kota1->firstEdge = E;
    }
}

void disconnectNode(GraphKota &G, string namaKota1, string namaKota2) {
    adrKota kota1 = findNode(G, namaKota1);
    adrKota kota2 = findNode(G, namaKota2);
    if (kota1 != nullptr && kota2 != nullptr) {
        adrEdge prev = nullptr;
        adrEdge curr = kota1->firstEdge;
        while (curr != nullptr && curr->kotaTujuan != kota2) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != nullptr) {
            if (prev == nullptr) {
                kota1->firstEdge = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
        }
    }
}

void deleteNode(GraphKota &G, string namaKota) {
    adrKota target = findNode(G, namaKota);
    if (target != nullptr) {
        adrKota P = G.First;
        while (P != nullptr) {
            if (P != target) {
                disconnectNode(G, P->namaKota, namaKota);
            }
            P = P->next;
        }
        adrEdge e = target->firstEdge;
        while (e != nullptr) {
            adrEdge del = e;
            e = e->next;
            delete del;
        }
        if (G.First == target) {
            G.First = target->next;
        } else {
            adrKota prev = G.First;
            while (prev->next != target) {
                prev = prev->next;
            }
            prev->next = target->next;
        }
        delete target;
    }
}

void printGraph(GraphKota G) {
    adrKota P = G.First;
    while (P != nullptr) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != nullptr) {
            cout << E->kotaTujuan->namaKota << "(" << E->jarak << " KM)";
            if (E->next != nullptr) {
                cout << ", ";
            }
            E = E->next;
        }
        cout << "," << endl;
        P = P->next;
    }
}

void resetVisited(GraphKota &G) {
    adrKota P = G.First;
    while (P != nullptr) {
        P->visited = 0;
        P = P->next;
    }
}

void printBFS(GraphKota G, string namaKotaAwal) {
    resetVisited(G);
    adrKota startNode = findNode(G, namaKotaAwal);
    if (startNode == nullptr) {
        return;
    }

    queue<adrKota> Q;
    startNode->visited = 1;
    Q.push(startNode);

    cout << "BFS Traversal: ";
    while (!Q.empty()) {
        adrKota current = Q.front();
        Q.pop();
        cout << current->namaKota << " - ";

        adrEdge E = current->firstEdge;
        while (E != nullptr) {
            if (E->kotaTujuan->visited == 0) {
                E->kotaTujuan->visited = 1;
                Q.push(E->kotaTujuan);
            }
            E = E->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota G, string namaKotaAwal) {
    resetVisited(G);
    adrKota startNode = findNode(G, namaKotaAwal);
    if (startNode == nullptr) {
        return;
    }

    stack<adrKota> S;
    S.push(startNode);

    cout << "DFS Traversal: ";
    while (!S.empty()) {
        adrKota current = S.top();
        S.pop();

        if (current->visited == 0) {
            current->visited = 1;
            cout << current->namaKota << " - ";

            adrEdge E = current->firstEdge;
            while (E != nullptr) {
                if (E->kotaTujuan->visited == 0) {
                    S.push(E->kotaTujuan);
                }
                E = E->next;
            }
        }
    }
    cout << endl;
}