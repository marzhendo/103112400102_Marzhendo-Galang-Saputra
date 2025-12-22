#include "mll.h"
using namespace std;

int main() {
    // 1) Create List
    multiLinkedList MLL;
    createListParent(MLL);
    
    // 2) Insert Data
    
    parentAddress P1 = alokasiNodeParent("G001", "Action");
    insertFirstParent(MLL, P1);
    
    childAddress C1 = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(P1, C1);
    
    parentAddress P2 = alokasiNodeParent("G002", "Comedy");
    insertFirstParent(MLL, P2);
    
    childAddress C2 = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(P2, C2);
    
    childAddress C3 = alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(P2, C3);
    
    parentAddress P3 = alokasiNodeParent("G003", "Horror");
    insertFirstParent(MLL, P3);
    
    childAddress C_Horror = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(P3, C_Horror);
    
    parentAddress P4 = alokasiNodeParent("G004", "Romance");
    insertFirstParent(MLL, P4);
    
    childAddress C4 = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(P4, C4);
    
    childAddress C5 = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(P4, C5);

    // 3) Print Struktur MLL
    cout << "========== Struktur Multi Linked List ==========" << endl;
    printStrukturMLL(MLL);

    
    // 4) Search Film by Rating Range 8.0 - 8.5
    cout << "\n========== Search by Rating ==========" << endl;
    searchFilmByRatingRange(MLL, 8.0, 8.5);
    
    //5) Delete Node G002 (Comedy)
    cout << "\n========== Delete Genre G002 (Comedy) ==========" << endl;
    deleteAfterParent(MLL, P1); 
    
    // 6) Print Struktur Akhir 
    printStrukturMLL(MLL);
    
    return 0;
}
