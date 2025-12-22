#ifndef GRAPHKOTA_H
#define GRAPHKOTA_H
#include <iostream>
#include <string>
using namespace std;
struct ElmEdge;
struct ElmKota;
typedef struct ElmKota* adrKota;
typedef struct ElmEdge* adrEdge;
struct ElmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};
struct ElmKota {
    string namaKota;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};
struct GraphKota {
    adrKota First;
};
void createGraph(GraphKota &G);
adrKota alokasiNode(string namaKota);
adrEdge alokasiEdge(adrKota kotaTujuan, int jarak);
void insertNode(GraphKota &G, adrKota nodeKota);
adrKota findNode(GraphKota G, string namaKota);
void connectNode(GraphKota &G, string namaKota1, string namaKota2, int jarak);
void disconnectNode(GraphKota &G, string namaKota1, string namaKota2);
void deleteNode(GraphKota &G, string namaKota);
void printGraph(GraphKota G);
// bagian b
void resetVisited(GraphKota &G);
void printBFS(GraphKota G, string namaKotaAwal);
void printDFS(GraphKota G, string namaKotaAwal);
#endif