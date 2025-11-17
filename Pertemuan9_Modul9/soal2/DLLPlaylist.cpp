#include "DLLPlaylist.h"
#include <iostream>
using namespace std;
bool isEmpty(List List) {
    if(List.head == Nill) {
        return true;
    } else {
        return false;
    }
}
void createList(List &List) {
    List.head = Nill;
    List.tail = Nill;
}

address allocate(string tittle, string artist, int durationSec, int playCount, float rating) {
    address nodeBaru = new Node;
    nodeBaru->info.Tittle = tittle;
    nodeBaru->info.Artist = artist;
    nodeBaru->info.DurationSec = durationSec;
    nodeBaru->info.PlayCount = playCount;
    nodeBaru->info.Rating = rating;
    nodeBaru->next = Nill;
    nodeBaru->prev = Nill;
    return nodeBaru;
}

void deallocate(address &node) {
    node->next = Nill;
    node->prev = Nill;
    delete node;
}

void insertFirst(List &List, address nodeBaru) {
    if(isEmpty(List)) {
        List.head = nodeBaru;
        List.tail = nodeBaru;
    } else {
        nodeBaru->next = List.head;
        List.head->prev = nodeBaru;
        List.head = nodeBaru;
    }
}

void insertAfter(List &List, address nodeBaru, address Prev) {
    if (Prev != Nill) {
        nodeBaru->next = Prev->next;
        nodeBaru->prev = Prev;
        if (Prev->next != Nill) {
            Prev->next->prev = nodeBaru;
        } else {
            List.tail = nodeBaru; // Update tail if inserted at the end
        }
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid." << endl;
    }
}

void insertLast(List &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.head = nodeBaru;
        List.tail = nodeBaru;
    } else {
        nodeBaru->prev = List.tail;
        List.tail->next = nodeBaru;
        List.tail = nodeBaru;
    }
}

void insertBefore(List &List, address nodeBaru, address Succ) {
    if (Succ != Nill) {
        nodeBaru->next = Succ;
        nodeBaru->prev = Succ->prev;
        if (Succ->prev != Nill) {
            Succ->prev->next = nodeBaru;
        } else {
            List.head = nodeBaru; // Update head if inserted at the beginning
        }
        Succ->prev = nodeBaru;
    } else {
        cout << "Node berikutnya tidak valid." << endl;
    }
}

void deleteFirst(List &List, address &nodeHapus) {
    if (!isEmpty(List)) {
        nodeHapus = List.head;
        List.head = List.head->next;
        if (List.head != Nill) {
            List.head->prev = Nill;
        } else {
            List.tail = Nill; // List is now empty
        }
        nodeHapus->next = Nill;
        nodeHapus->prev = Nill;
    } else {
        nodeHapus = Nill;
        cout << "List kosong, tidak ada yang dihapus." << endl;
    }
}

void deleteAfter(List &List, address &nodeHapus, address Prev) {
    if (Prev != Nill && Prev->next != Nill) {
        nodeHapus = Prev->next;
        Prev->next = nodeHapus->next;
        if (nodeHapus->next != Nill) {
            nodeHapus->next->prev = Prev;
        } else {
            List.tail = Prev; // Update tail if last node is deleted
        }
        nodeHapus->next = Nill;
        nodeHapus->prev = Nill;
    } else {
        nodeHapus = Nill;
        cout << "Node sebelumnya tidak valid atau tidak ada node setelahnya." << endl;
    }
}

void deleteLast(List &List, address &nodeHapus) {
    if (!isEmpty(List)) {
        nodeHapus = List.tail;
        List.tail = List.tail->prev;
        if (List.tail != Nill) {
            List.tail->next = Nill;
        } else {
            List.head = Nill; // List is now empty
        }
        nodeHapus->next = Nill;
        nodeHapus->prev = Nill;
    } else {
        nodeHapus = Nill;
        cout << "List kosong, tidak ada yang dihapus." << endl;
    }
}

void deleteBefore(List &List, address &nodeHapus, address Succ) {
    if (Succ != Nill && Succ->prev != Nill) {
        nodeHapus = Succ->prev;
        Succ->prev = nodeHapus->prev;
        if (nodeHapus->prev != Nill) {
            nodeHapus->prev->next = Succ;
        } else {
            List.head = Succ; // Update head if first node is deleted
        }
        nodeHapus->next = Nill;
        nodeHapus->prev = Nill;
    } else {
        nodeHapus = Nill;
        cout << "Node berikutnya tidak valid atau tidak ada node sebelumnya." << endl;
    }
}

void updateAtPosition(List &List, int posisi, Song dataBaru) {
    if (!isEmpty(List)) {
        address curr = List.head;
        int index = 0;
        while (curr != Nill && index < posisi) {
            curr = curr->next;
            index++;
        }
        if (curr != Nill) {
            curr->info = dataBaru;
        } else {
            cout << "Posisi tidak valid." << endl;
        }
    } else {
        cout << "List kosong." << endl;
    }
}

void updateBefore(List &List, address Succ, Song dataBaru) {
    if (Succ != Nill && Succ->prev != Nill) {
        Succ->prev->info = dataBaru;
    } else {
        cout << "Node berikutnya tidak valid atau tidak ada node sebelumnya." << endl;
    }
}

void viewList(List List) {
    if (!isEmpty(List)) {
        address curr = List.head;
        int index = 0;
        while (curr != Nill) {
            cout << "Song " << index + 1 << ":" << endl;
            cout << "Tittle: " << curr->info.Tittle << endl;
            cout << "Artist: " << curr->info.Artist << endl;
            cout << "Duration (sec): " << curr->info.DurationSec << endl;
            cout << "Play Count: " << curr->info.PlayCount << endl;
            cout << "Rating: " << curr->info.Rating << endl;
            cout << "------------------------" << endl;
            curr = curr->next;
            index++;
        }
    } else {
        cout << "List kosong." << endl;
    }
}

void searchByPopularityRange(List List, float minScore, float maxScore) {
    if (!isEmpty(List)) {
        address curr = List.head;
        bool found = false;
        while (curr != Nill) {
            if (curr->info.Rating >= minScore && curr->info.Rating <= maxScore) {
                cout << "Song ditemukan dalam rentang popularitas:" << endl;
                cout << "Tittle: " << curr->info.Tittle << endl;
                cout << "Artist: " << curr->info.Artist << endl;
                cout << "Duration (sec): " << curr->info.DurationSec << endl;
                cout << "Play Count: " << curr->info.PlayCount << endl;
                cout << "Rating: " << curr->info.Rating << endl;
                cout << "------------------------" << endl;
                found = true;
            }
            curr = curr->next;
        }
        if (!found) {
            cout << "Tidak ada lagu dalam rentang popularitas yang ditentukan." << endl;
        }
    } else {
        cout << "List kosong." << endl;
    }
}

