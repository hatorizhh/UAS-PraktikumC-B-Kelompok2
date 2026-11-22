#ifndef FUNGSI_H
#define FUNGSI_H
#define FILE_DB "../data/keuangan.bin"
#define FILE_LAPORAN "../data/laporan_bulanan.csv"
#define MAKS 100

typedef struct {
    int id;
    char tanggal[11];
    char kategori[50];
    char tipe[12];
    long long nominal;
} CatatanKeuangan;

typedef struct {
    long long pemasukan;
    long long pengeluaran;
    long long saldo;
} Ringkasan;

// Fungsi yang Farhan Buat
void tambahCatatan(CatatanKeuangan data[], int *jumlah, CatatanKeuangan catatan);
void tampilCatatan(CatatanKeuangan data[], int jumlah);
void ubahCatatan(CatatanKeuangan data[], int jumlah, int id, long long nominalBaru);
void hapusCatatan(CatatanKeuangan data[], int *jumlah, int id);

// Fungsi yang Jessica Buat
Ringkasan hitungRingkasan(CatatanKeuangan data[], int jumlah); 
int eksporLaporan(CatatanKeuangan data[], int jumlah);

// Fungsi yang Inaya Buat
void tampilBantuan(void);

// Fungsi yang Syaqila Buat
int simpanKeBinary(CatatanKeuangan data[], int jumlah);
int muatDariBinary(CatatanKeuangan data[]);

#endif
