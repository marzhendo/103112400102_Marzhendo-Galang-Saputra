#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
struct Node {
    infotype info;
    Node *left;
    Node *right;
};
typedef Node* address;

address alokasi(infotype x);                                  
void insertNode(address &root, infotype x);                   
address findNode(infotype x, address root);                   
void printInOrder(address root);                              

int hitungKedalaman(address root);                            
int hitungJumlahNode(address root);                           
int hitungTotal(address root);                                

void printPreOrder(address root);                             
void printPostOrder(address root);                            

#endif
