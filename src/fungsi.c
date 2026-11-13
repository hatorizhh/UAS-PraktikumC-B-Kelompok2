#include"fungsi.h"
#include<stdio.h>
#include<string.h>

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




// Fungsi yang Jessica Buat





// Fungsi yang Inaya Buat




// Fungsi yang Syaqila Buat


