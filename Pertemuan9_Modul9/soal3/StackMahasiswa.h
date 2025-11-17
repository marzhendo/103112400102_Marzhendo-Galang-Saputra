#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#define Nill NULL
#include <iostream>
using namespace std;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

const int MAX = 6;

typedef Mahasiswa dataMahasiswa;
typedef struct StackNode *address;

struct StackMahasiswa {
    dataMahasiswa info[MAX];
    int top;
};

bool isEmpty(StackMahasiswa S);
bool isFull(StackMahasiswa S);
void createStack(StackMahasiswa &S);
void push(StackMahasiswa &S, dataMahasiswa dataBaru);
dataMahasiswa pop(StackMahasiswa &S);
void update(StackMahasiswa &S, int posisi, dataMahasiswa dataBaru);
void view(StackMahasiswa S);
void searchNilaiAkhir(StackMahasiswa S, float nilaiAkhirMin, float nilaiAkhirMax);
void maxNilaiAkhir(StackMahasiswa S);

#endif