#include"fungsi.h"
#include<stdio.h>
#include<string.h>
#define MAKS 100
// Fungsi yang Zian Buat


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

// Fungsi yang Jessica Buat





// Fungsi yang Inaya Buat




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


