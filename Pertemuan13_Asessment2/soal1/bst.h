#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
using namespace std;

typedef struct node* address;

struct node {
    int idProduk;
    string namaProduk;
    int stok;
    address left;
    address right;
};

void insertNode(address &root, int idProduk, string namaProduk, int stok);
address searchById(address root, int idProduk);
address searchByProduct(address root, string namaProduk);
void deleteNode(address &root, int idProduk);
void inOrder(address root);
void preOrder(address root);
void postOrder(address root);
void deleteTree(address &root);
address findMin(address root);
address findMax(address root);

#endif

