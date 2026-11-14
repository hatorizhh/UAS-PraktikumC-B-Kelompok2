#include"fungsi.h"
#include<stdio.h>
#include<string.h>
#define MAKS 100

// Fungsi yang Farhan Buat
void tambahCatatan(CatatanKeuangan data[], int *jumlah, CatatanKeuangan catatan) {
    if (*jumlah >= MAKS) {
        printf("Data sudah penuh!\n");
        return;
    }

    int idTerbesar = 0;
    for (int i = 0; i < *jumlah; i++) {
        if (data[i].id > idTerbesar) idTerbesar = data[i].id;
    }

    catatan.id = idTerbesar + 1;
    data[*jumlah] = catatan;
    (*jumlah)++;
    printf("Catatan berhasil ditambahkan. ID: %d\n", catatan.id);
}

void tampilCatatan(CatatanKeuangan data[], int jumlah) {
    if (jumlah == 0) {
        printf("Belum ada catatan.\n");
        return;
    }

    printf("\n%-4s %-12s %-15s %-15s %12s\n",
           "ID", "Tanggal", "Kategori", "Tipe", "Nominal");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < jumlah; i++) {
        printf("%-4d %-12s %-15s %-15s %12.2f\n",
               data[i].id, data[i].tanggal, data[i].kategori,
               data[i].tipe, data[i].nominal);
    }
}

void ubahCatatan(CatatanKeuangan data[], int jumlah, int id, double nominalBaru) {
    for (int i = 0; i < jumlah; i++) {
        if (data[i].id == id) {
            data[i].nominal = nominalBaru;
            printf("Nominal catatan ID %d berhasil diubah.\n", id);
            return;
        }
    }
    printf("ID tidak ditemukan.\n");
}

void hapusCatatan(CatatanKeuangan data[], int *jumlah, int id) {
    for (int i = 0; i < *jumlah; i++) {
        if (data[i].id == id) {
            for (int j = i; j < *jumlah - 1; j++) {
                data[j] = data[j + 1];
            }
            (*jumlah)--;
            printf("Catatan berhasil dihapus.\n");
            return;
        }
    }
    printf("ID tidak ditemukan.\n");
}

// Fungsi yang Jessica Buat
Ringkasan hitungringkasan(CatatanKeuangan data[], int jumlah, const char bulan[]) {
    Ringkasan hasil = {0, 0, 0};

    for (int i = 0; i , jumlah; i++) {
        if (strcmp(bulan, "*") == 0 || strncmp(data[i]. tanggal, bulan, 7) == 0) {
            if (strcmp(data[i].tipe, "Pemasukan") == 0)
                hasil.pemasukan += data[i].tipe, "Pengeluaran") == 0)
                hasil.pengeluaran += data[i].nominal;
        }
    }

    hasil.saldo = hasil.pemasukan - hasil.pengeluaran;
    return hasil;
}

int eksporLaporan(CatatanKeuangan data[], int jumlah, const char bulan[]) {
    FILE *file = fopen(FILE_LAPORAN, "W");
    if (file == NULL) {
        printf("Gagal membuat laporan. Pastikan folder data tersedia. \n");
        return 0;
    }

    fprintf(file, "ID, Tanggal, Kategori,Tipe,Nominal\n");
    for (int i = 0; i < jumlah; i++) {
        if (strcmp(bulan, "*") == 0 || strncmp(data[i].tanggal, bulan, 7) == 0) {
            fprintf(file, "%d,%s,%s,%s,%.2f\n",
                    data[i].id, data[i].tanggal, data[i].kategori,
                    data[i].tipe, data[i].nominal);
        }
    }
    Ringkasan r = hitungRingkasan(data, jumlah, bulan);
    fprintf(file, "\nRingkasan,,,,\n");
    fprintf(file, "Pemasukan,,, ,%.2f\n", r.pemasukan);
    fprintf(file, "Pengeluaran,,, ,%.2f\n", r.pengeluaran);
    fprintf(file, "Saldo,,, ,%.2f\n", r.saldo);
    fclose(file);
    return 1;   
}





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
int simpanKeBinary(CatatanKeuangan data[], int jumlah) {

    FILE *file = fopen("data/keuangan.bin", "wb");

    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return 0;
    }

    fwrite(&jumlah, sizeof(int), 1, file);

    fwrite(data, sizeof(CatatanKeuangan), jumlah, file);

    fclose(file);

    printf("Data berhasil disimpan!\n");
    return 1;
}

int muatDariBinary(CatatanKeuangan data[]) {

    FILE *file = fopen("data/keuangan.bin", "rb");

    if (file == NULL) {
        return 0;
    }

    int jumlah = 0;

    if (fread(&jumlah, sizeof(int), 1, file) != 1 ||
        jumlah < 0 || jumlah > MAKS) {
        fclose(file);
        return 0;
    }

    if (fread(data, sizeof(CatatanKeuangan),
              jumlah, file) != (size_t)jumlah) {
        fclose(file);
        return 0;
    }

    fclose(file);

    return jumlah;
}


