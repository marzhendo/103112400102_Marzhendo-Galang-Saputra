#include "mll.h"

using namespace std;

void createListParent(multiLinkedList &MLL) {
    MLL.firstParent = nullptr;
    MLL.lastParent = nullptr;
}

void createListChild(childAddress &firstChild, childAddress &lastChild) {
    firstChild = nullptr;
    lastChild = nullptr;
}

parentAddress alokasiNodeParent(string IDGenre, string namaGenre) {
    parentAddress newNode = new parentNode;
    newNode->IDGenre = IDGenre;
    newNode->namaGenre = namaGenre;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    createListChild(newNode->firstChild, newNode->lastChild);
    return newNode;
}

childAddress alokasiNodeChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm) {
    childAddress newNode = new childNode;
    newNode->IDFilm = IDFilm;
    newNode->judulFilm = judulFilm;
    newNode->durasiFilm = durasiFilm;
    newNode->tahunTayang = tahunTayang;
    newNode->ratingFilm = ratingFilm;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void dealokasiNodeParent(parentAddress &nodeParent) {
    delete nodeParent;
    nodeParent = nullptr;
}

void dealokasiNodeChild(childAddress &nodeChild) {
    delete nodeChild;
    nodeChild = nullptr;
}

// SAYA UBAH LOGIKANYA JADI INSERT LAST AGAR URUTAN SESUAI MAIN.CPP
// (G001 -> G002 -> G003 -> G004)
void insertFirstParent(multiLinkedList &MLL, parentAddress nodeParent) {
    if (MLL.firstParent == nullptr) {
        MLL.firstParent = nodeParent;
        MLL.lastParent = nodeParent;
    } else {
        // Logika Insert Last (agar urutan benar)
        MLL.lastParent->next = nodeParent;
        nodeParent->prev = MLL.lastParent;
        MLL.lastParent = nodeParent;
    }
}

void insertLastChild(parentAddress nodeParent, childAddress nodeChild) {
    if (nodeParent->firstChild == nullptr) {
        nodeParent->firstChild = nodeChild;
        nodeParent->lastChild = nodeChild;
    } else {
        nodeParent->lastChild->next = nodeChild;
        nodeChild->prev = nodeParent->lastChild;
        nodeParent->lastChild = nodeChild;
    }
}

void deleteAfterParent(multiLinkedList &MLL, parentAddress prevNode) {
    if (prevNode != nullptr && prevNode->next != nullptr) {
        parentAddress delNode = prevNode->next;
        
        // RE-LINKING POINTERS
        prevNode->next = delNode->next;
        if (delNode->next != nullptr) {
            delNode->next->prev = prevNode;
        } else {
            MLL.lastParent = prevNode;
        }
        
        // PENTING: Hapus anak-anaknya dulu sebelum hapus bapaknya!
        hapusListChild(delNode); 

        delNode->next = nullptr;
        delNode->prev = nullptr;
        dealokasiNodeParent(delNode);
    }
}

void hapusListChild(parentAddress nodeParent) {
    while (nodeParent->firstChild != nullptr) {
        childAddress delChild = nodeParent->firstChild;
        if (nodeParent->firstChild == nodeParent->lastChild) {
            nodeParent->firstChild = nullptr;
            nodeParent->lastChild = nullptr;
        } else {
            nodeParent->firstChild = delChild->next;
            nodeParent->firstChild->prev = nullptr;
            delChild->next = nullptr;
        }
        dealokasiNodeChild(delChild);
    }
}

void searchFilmByRatingRange(multiLinkedList MLL, float minRating, float maxRating) {
    if (MLL.firstParent == nullptr) {
        cout << "Multi Linked List kosong." << endl;
        return;
    }
    parentAddress P = MLL.firstParent;
    bool found = false;
    while (P != nullptr) {
        childAddress C = P->firstChild;
        while (C != nullptr) {
            if (C->ratingFilm >= minRating && C->ratingFilm <= maxRating) {
                found = true;
                cout << "Film ditemukan dalam genre " << P->namaGenre << ":" << endl;
                cout << "  ID Film: " << C->IDFilm << endl;
                cout << "  Judul Film: " << C->judulFilm << endl;
                cout << "  Durasi Film: " << C->durasiFilm << " menit" << endl;
                cout << "  Tahun Tayang: " << C->tahunTayang << endl;
                cout << "  Rating Film: " << C->ratingFilm << endl;
                cout << "-------------------------" << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
    if (!found) {
        cout << "Tidak ada film yang ditemukan dalam rentang rating tersebut." << endl;
    }
}

void printStrukturMLL(multiLinkedList MLL) {
    if (MLL.firstParent == nullptr) {
        cout << "Multi Linked List kosong." << endl;
        return;
    }
    parentAddress P = MLL.firstParent;
    int i = 1;
    while (P != nullptr) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre: " << P->IDGenre << endl;
        cout << "Nama Genre: " << P->namaGenre << endl;
        if (P->firstChild == nullptr) {
            cout << "  (tidak ada film dalam genre ini)" << endl;
        } else {
            childAddress C = P->firstChild;
            int j = 1;
            while (C != nullptr) {
                cout << "  - Child " << j << " :" << endl;
                cout << "      ID Film: " << C->IDFilm << endl;
                cout << "      Judul Film: " << C->judulFilm << endl;
                cout << "      Durasi Film: " << C->durasiFilm << " menit" << endl;
                cout << "      Tahun Tayang: " << C->tahunTayang << endl;
                cout << "      Rating Film: " << C->ratingFilm << endl;
                C = C->next;
                j++;
            }
        }
        cout << "--------------------------------" << endl;
        P = P->next;
        i++;
    }
}