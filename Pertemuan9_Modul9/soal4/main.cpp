#include "QueuePengiriman.h"
#include <iostream>
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q); //Soal 1 buat queue kosong
    // soal 2 buat tampilan menu seperti dibawah gunakan percabangan switch-case
    // --- Komaniya Ekspress ---
    // 1. Input Data Paket
    // 2. Hapus Data Paket
    // 3. Tampilkan queue paket
    //Pilihan anda: ...

    int pilihan;
    dataPaket paketBaru, paketHapus;
    cout << "--- Komaniya Ekspress ---" << endl;
    cout << "1. Input Data Paket" << endl;
    cout << "2. Hapus Data Paket" << endl;
    cout << "3. Tampilkan queue paket" << endl;
    cout << "4. Hitung Total Biaya Pengiriman" << endl;
    cout << "Pilihan anda: ";
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            for (int i = 0; i < 5; i++) {
                cout << "Masukkan data paket ke-" << i + 1 << ":" << endl;
                cout << "Kode Resi: ";
                cin >> paketBaru.KodeResi;
                cout << "Nama Pengirim: ";
                cin >> paketBaru.NamaPengirim;
                cout << "Berat Barang (gram): ";
                cin >> paketBaru.BeratBarang;
                cout << "Tujuan: ";
                cin >> paketBaru.Tujuan;
                enqueue(Q, paketBaru);
            }
            break;
        case 2:
            for (int i = 0; i < 2; i++) {
                paketHapus = dequeue(Q);
                cout << "Paket yang dihapus:" << endl;
                cout << "Kode Resi: " << paketHapus.KodeResi << endl;
                cout << "Nama Pengirim: " << paketHapus.NamaPengirim << endl;
                cout << "Berat Barang: " << paketHapus.BeratBarang << " gram" << endl;
                cout << "Tujuan: " << paketHapus.Tujuan << endl;
            }
            break;
        case 3:
            viewQueue(Q);
            break;
        case 4:
            totalBiayaPengiriman(Q); //soal b tampilkan total biaya pengiriman dari semua paket dalam queue
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
    }
    //soal 4 tampilkan queue yang sudah diinputkan data paket
    viewQueue(Q);

    //soal 5 lakukan dequeue sebanyak 1x
    paketHapus = dequeue(Q);
    //soal6 tampilkan data paket yang di dequeue
    cout << "Paket yang dihapus:" << endl;
    cout << "Kode Resi: " << paketHapus.KodeResi << endl;
    cout << "Nama Pengirim: " << paketHapus.NamaPengirim << endl;
    cout << "Berat Barang: " << paketHapus.BeratBarang << " gram" << endl;
    cout << "Tujuan: " << paketHapus.Tujuan << endl;
    cout << endl;
    return 0;
}   

