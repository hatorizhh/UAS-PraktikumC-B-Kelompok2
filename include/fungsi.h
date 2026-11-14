#ifndef FUNGSI_H
#define FUNGSI_H

typedef struct {
    int id;
    char tanggal[11];
    char kategori[50];
    char tipe[12];
    long nominal;
} CatatanKeuangan;

typedef struct {
    double pemasukan;
    double pengeluaran;
    double saldo;
} Ringkasan;

// Fungsi yang Farhan Buat
void tambahCatatan(CatatanKeuangan data[], int *jumlah, CatatanKeuangan catatan)
void tampilCatatan(CatatanKeuangan data[], int jumlah)
void ubahCatatan(CatatanKeuangan data[], int jumlah, int id, double nominalBaru)


// Fungsi yang Jessica Buat





// Fungsi yang Inaya Buat




// Fungsi yang Syaqila Buat
void simpanKeBinary(CatatanKeuangan data[], int jumlah);
int muatDariBinary(CatatanKeuangan data[]);





#endif
