#include <iostream>
#include "bst.h"
using namespace std;

int main() {
    address root = nullptr;
    //1) input data produk
    insertNode(root, 50, "Monitor LED", 10);
    insertNode(root, 30, "Keyboard RGB", 20);
    insertNode(root, 70, "Mouse Gaming", 15);
    insertNode(root, 20, "Kabel HDMI", 50);
    insertNode(root, 40, "Headset 7.1", 12);
    insertNode(root, 60, "Webcam HD", 8);
    insertNode(root, 80, "Speaker BT", 5);

    //2) panggil inOrder(), preOrder(), dan postOrder()
    cout << "In-Order Traversal:" << endl;
    inOrder(root);
    cout << endl;

    cout << "Pre-Order Traversal:" << endl;
    preOrder(root);
    cout << endl;

    cout << "Post-Order Traversal:" << endl;
    postOrder(root);
    cout << endl;

    //3) searchById(40)
    int searchId = 40;
    address foundById = searchById(root, searchId);
    if (foundById != nullptr) {
        cout << "Produk ditemukan berdasarkan ID " << searchId << ": "
             << foundById->namaProduk << " dengan stok " << foundById->stok << endl;
    } else {
        cout << "Produk dengan ID " << searchId << " tidak ditemukan." << endl;
    }

    //4) searchById(99)
    searchId = 99;
    foundById = searchById(root, searchId);
    if (foundById != nullptr) {
        cout << "Produk ditemukan berdasarkan ID " << searchId << ": "
             << foundById->namaProduk << " dengan stok " << foundById->stok << endl;
    } else {
        cout << "Produk dengan ID " << searchId << " tidak ditemukan." << endl;
    }

    //5) searchByProduct("Webcam HD")
    string searchProduct = "Webcam HD";
    address foundByProduct = searchByProduct(root, searchProduct);
    if (foundByProduct != nullptr) {
        cout << "Produk ditemukan berdasarkan nama " << searchProduct << ": "
             << foundByProduct->namaProduk << " dengan stok " << foundByProduct->stok << endl;
    } else {
        cout << "Produk dengan nama " << searchProduct << " tidak ditemukan." << endl;
    }
    //6) searchByProduct("Printer")
    searchProduct = "Printer";
    foundByProduct = searchByProduct(root, searchProduct);
    if (foundByProduct != nullptr) {
        cout << "Produk ditemukan berdasarkan nama " << searchProduct << ": "
             << foundByProduct->namaProduk << " dengan stok " << foundByProduct->stok << endl;
    } else {
        cout << "Produk dengan nama " << searchProduct << " tidak ditemukan." << endl;
    }
    //7) Panggil findMin() dan findMax()
    address minNode = findMin(root);
    if (minNode != nullptr) {
        cout << "Produk dengan ID terkecil: " << minNode->idProduk << ", Nama: " << minNode->namaProduk << ", Stok: " << minNode->stok << endl;
    }
    address maxNode = findMax(root);
    if (maxNode != nullptr) {
        cout << "Produk dengan ID terbesar: " << maxNode->idProduk << ", Nama: " << maxNode->namaProduk << ", Stok: " << maxNode->stok << endl;
    }
    //8) deleteNode(20), deleteNode(30), deleteNode(50)
    deleteNode(root, 20);
    //9 inOrder() setelah penghapusan
    cout << "In-Order Traversal setelah menghapus ID 20:" << endl;
    inOrder(root);
    cout << endl;
    //10) deleteNode(30)
    deleteNode(root, 30);
    //11) inOrder() setelah penghapusan
    cout << "In-Order Traversal setelah menghapus ID 30:" << endl;
    inOrder(root);
    cout << endl;
    //12) deleteNode(50)
    deleteNode(root, 50);
    cout << "In-Order Traversal setelah menghapus ID 50:" << endl;
    //13) inOrder() setelah penghapusan
    inOrder(root);
    cout << endl;
    //14) deleteTree()
    deleteTree(root);
    cout << "Tree telah dihapus." << endl;
    //15) inOrder() setelah deleteTree()
    cout << "In-Order Traversal setelah menghapus seluruh tree:" << endl;
    inOrder(root);
    cout << endl;
    
    return 0;
}