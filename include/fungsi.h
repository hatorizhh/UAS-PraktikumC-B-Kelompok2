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
void hapusCatatan(CatatanKeuangan data[], int *jumlah, int id)

// Fungsi yang Jessica Buat
Ringkasan hitungRingkasan(CatatanKeuangan data[], int jumlah, const char bulan[]) 
int eksporLaporan(CatatanKeuangan data[], int jumlah, const char bulan[]) 

// Fungsi yang Inaya Buat
void tampilBantuan(void) {
    printf("Personal Expense Tracker\n");
    printf("Perintah:\n");
    printf("  program              Menjalankan menu\n");
    printf("  program --help       Menampilkan bantuan\n");
    printf("  program --laporan    Membuat laporan semua bulan\n");
    printf("  program --tambah Pemasukan|Pengeluaran Kategori Nominal\n");
    printf("Contoh:\n");
    printf("  program --tambah Pengeluaran Makan 25000\n");
}

// Fungsi yang Syaqila Buat
int simpanKeBinary(CatatanKeuangan data[], int jumlah);
int muatDariBinary(CatatanKeuangan data[]);

#endif
