#ifndef MLL_H
#define MLL_H
#include <iostream>
#include <string>
using namespace std;
struct childNode;
struct parentNode;
typedef struct childNode* childAddress;
typedef struct parentNode* parentAddress;
struct childNode {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    childAddress next;
    childAddress prev;
};
struct parentNode {
    string IDGenre;
    string namaGenre;
    parentAddress next;
    parentAddress prev;
    childAddress firstChild;
    childAddress lastChild;
};
struct multiLinkedList {
    parentAddress firstParent;
    parentAddress lastParent;
};
void createListParent(multiLinkedList &MLL);
void createListChild(childAddress &firstChild, childAddress &lastChild);
parentAddress alokasiNodeParent(string IDGenre, string namaGenre);
childAddress alokasiNodeChild(string IDFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);
void dealokasiNodeParent(parentAddress &nodeParent);
void dealokasiNodeChild(childAddress &nodeChild);
void insertFirstParent(multiLinkedList &MLL, parentAddress nodeParent);
void insertLastChild(parentAddress nodeParent, childAddress nodeChild);
void deleteAfterParent(multiLinkedList &MLL, parentAddress prevNode);
void hapusListChild(parentAddress nodeParent);
void searchFilmByRatingRange(multiLinkedList MLL, float minRating, float maxRating);
void printStrukturMLL(multiLinkedList MLL);
#endif