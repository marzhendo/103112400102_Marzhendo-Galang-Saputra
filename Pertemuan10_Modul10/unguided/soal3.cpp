#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;
    insertNode(root, 4);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 1);
    insertNode(root, 3);
    insertNode(root, 5);
    insertNode(root, 7);

    cout << "Pre-order  : ";
    printPreOrder(root);
    cout << endl;

    cout << "Post-order : ";
    printPostOrder(root);
    cout << endl;

    return 0;
}
