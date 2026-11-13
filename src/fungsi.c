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


