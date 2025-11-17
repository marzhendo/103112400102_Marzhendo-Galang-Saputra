#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

bool isEmpty(QueueEkspedisi Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void createQueue(QueueEkspedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}

void enqueue(QueueEkspedisi &Q, dataPaket dataBaru) {
    if (!isFull(Q)) {
        if (isEmpty(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = dataBaru;
    } else {
        cout << "Queue penuh, tidak dapat menambahkan paket baru." << endl;
    }
}

dataPaket dequeue(QueueEkspedisi &Q) {
    if (!isEmpty(Q)) {
        dataPaket dataKeluar = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAX;
        }
        return dataKeluar;
    } else {
        cout << "Queue kosong, tidak ada paket yang dapat dihapus." << endl;
        return {"", "", 0, ""};
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (!isEmpty(Q)) {
        int i = Q.head;
        int index = 1;
        cout << "Daftar Paket dalam Queue:" << endl;
        while (true) {
            cout << "Paket ke-" << index << ":" << endl;
            cout << "Kode Resi: " << Q.info[i].KodeResi << endl;
            cout << "Nama Pengirim: " << Q.info[i].NamaPengirim << endl;
            cout << "Berat Barang: " << Q.info[i].BeratBarang << " gram" << endl;
            cout << "Tujuan: " << Q.info[i].Tujuan << endl;
            cout << "------------------------" << endl;
            if (i == Q.tail) {
                break;
            }
            i = (i + 1) % MAX;
            index++;
        }
    } else {
        cout << "Queue kosong." << endl;
    }
}

void totalBiayaPengiriman(QueueEkspedisi Q) {
    if (!isEmpty(Q)) {
        int totalBiaya = 0;
        int i = Q.head;
        while (true) {
            int biaya;
            if (Q.info[i].BeratBarang <= 1000) {
                biaya = 8250;
            } else {
                biaya = 8250 + ((Q.info[i].BeratBarang - 1000 + 499) / 500) * 3000;
            }
            totalBiaya += biaya;
            if (i == Q.tail) {
                break;
            }
            i = (i + 1) % MAX;
        }
        cout << "Total Biaya Pengiriman untuk semua paket: Rp " << totalBiaya << endl;
    } else {
        cout << "Queue kosong, tidak ada biaya pengiriman." << endl;
    }
}