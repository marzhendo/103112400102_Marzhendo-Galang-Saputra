#include "bst.h"
using namespace std;

void insertNode(address &root, int idProduk, string namaProduk, int stok) {
    if (root == nullptr) {
        root = new node;
        root->idProduk = idProduk;
        root->namaProduk = namaProduk;
        root->stok = stok;
        root->left = nullptr;
        root->right = nullptr;
        cout << "Produk dengan ID " << idProduk << " berhasil ditambahkan." << endl;
    } else if (idProduk < root->idProduk) {
        insertNode(root->left, idProduk, namaProduk, stok);
    } else if (idProduk > root->idProduk) {
        insertNode(root->right, idProduk, namaProduk, stok);
    } else {
        cout << "ID Produk " << idProduk << " sudah ada!" << endl;
    }
}

address searchById(address root, int idProduk) {
    if (root == nullptr || root->idProduk == idProduk) {
        return root;
    } else if (idProduk < root->idProduk) {
        return searchById(root->left, idProduk);
    } else {
        return searchById(root->right, idProduk);
    }
}

address searchByProduct(address root, string namaProduk) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->namaProduk == namaProduk) {
        return root;
    }
    address leftSearch = searchByProduct(root->left, namaProduk);
    if (leftSearch != nullptr) {
        return leftSearch;
    }
    return searchByProduct(root->right, namaProduk);
}

void deleteNode(address &root, int idProduk) {
    if (root == nullptr) return;
    if (idProduk < root->idProduk) {
        deleteNode(root->left, idProduk);
    } else if (idProduk > root->idProduk) {
        deleteNode(root->right, idProduk);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
            address temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
            address temp = root;
            root = root->left;
            delete temp;
        } else {
            address minNode = findMin(root->right);
            root->idProduk = minNode->idProduk;
            root->namaProduk = minNode->namaProduk;
            root->stok = minNode->stok;
            deleteNode(root->right, minNode->idProduk);
        }
    }
}

void inOrder(address root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << "ID: " << root->idProduk << ", Nama: " << root->namaProduk << ", Stok: " << root->stok << endl;
        inOrder(root->right);
    }
}

void preOrder(address root) {
    if (root != nullptr) {
        cout << "ID: " << root->idProduk << ", Nama: " << root->namaProduk << ", Stok: " << root->stok << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << "ID: " << root->idProduk << ", Nama: " << root->namaProduk << ", Stok: " << root->stok << endl;
    }
}

void deleteTree(address &root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = nullptr;
    }
}

address findMin(address root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

address findMax(address root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

