#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"../include/fungsi.h"

int main(int argc, char*argv[]){
    CatatanKeuangan data[MAKS];
    CatatanKeuangan baru;
    int jumlah = muatDariBinary(data);
    int pilihan,id,i;
    long long nominalBaru;
    Ringkasan Total;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(baru.tanggal, sizeof(baru.tanggal), "%Y-%m-%d", tm_info);
    char Tipe[20];
    char Kategori[20];

    if(argc == 1){
        do {
            printf("\n========= PILIHAN MENU =========\n");
            printf("1. Tambah Catatan\n");
            printf("2. Tampilkan Catatan\n");
            printf("3. Ubah Nominal Catatan\n");
            printf("4. Hapus Catatan\n");
            printf("5. Lihat Ringkasan Keuangan\n");
            printf("6. Ekspor Laporan CSV\n");
            printf("0. Keluar\n");
            printf("Pilih menu: ");
            scanf(" %d", &pilihan);
            switch(pilihan){   
            case 1:
                printf("Masukkan Tipe(Pemasukan/Pengeluaran): ");scanf(" %s",Tipe);
                if(strcmp(Tipe,"Pemasukan")==0){
                }
                else if(strcmp(Tipe,"pemasukan")==0){
                }
                else if(strcmp(Tipe,"Pengeluaran")==0){
                }
                else if(strcmp(Tipe,"pengeluaran")==0){
                }
                else{
                    printf("Mohon pilih tipe antara pemasukan dan pengeluaran\n");
                    break;
                }
                printf("Masukkan Kategori: ");scanf(" %s",Kategori);
                printf("Masukkan Nominal: ");scanf(" %lld",&nominalBaru);
                if(nominalBaru<=0){
                    printf("Nominal tidak valid\n");
                    break;
                }
                strcpy(baru.tipe,Tipe);
                strcpy(baru.kategori,Kategori);
                baru.nominal=nominalBaru;
                tambahCatatan(data,&jumlah,baru);
                simpanKeBinary(data,jumlah);
                break;
            case 2:
                tampilCatatan(data,jumlah);
                break;
            case 3:
                printf("Masukkan id yang mau di ubah: ");scanf(" %d",&id);
                printf("Masukkan Nominal: ");scanf(" %lld",&nominalBaru);
                ubahCatatan(data, jumlah, id, nominalBaru);
                simpanKeBinary(data, jumlah);
                break;
            case 4:
                printf("Masukkan id yang mau di hapus: ");scanf(" %d",&id);
                hapusCatatan(data,&jumlah,id);
                simpanKeBinary(data, jumlah);
                break;
            case 5:
                Total=hitungRingkasan(data,jumlah);
                printf("Total Pemasukan: %lld\nTotal Pengeluaran: %lld\nTotal Saldo: %lld\n",Total.pemasukan,Total.pengeluaran,Total.saldo);
                break;
            case 6:
                if(eksporLaporan(data,jumlah)==1){
                    printf("Ekspor Berhasil\n");
                }
                else{
                    printf("Ekspor gagal\n");
                }
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Input salah\n");
                break;
        }
    }while(pilihan!=0);
}
    else{
        if(argc==5){
            if(strcmp(argv[1],"--tambah")==0){
                long long Nominal=atof(argv[4]);
                if(Nominal<=0){
                    printf("Nominal tidak Valid\n");
                }
                else if(strcmp(argv[2],"Pemasukan")==0 || strcmp(argv[2],"pemasukan")==0 ){
                    strcpy(baru.tipe, argv[2]);
                    strcpy(baru.kategori, argv[3]);
                    baru.nominal = Nominal;
                    tambahCatatan(data, &jumlah, baru);
                    simpanKeBinary(data, jumlah);
                }
                else if(strcmp(argv[2],"Pengeluaran")==0 || strcmp(argv[2],"pengeluaran")==0){
                    strcpy(baru.tipe, argv[2]);
                    strcpy(baru.kategori, argv[3]);
                    baru.nominal = Nominal;
                    tambahCatatan(data, &jumlah, baru);
                    simpanKeBinary(data, jumlah);
                }
                else {
                    printf("Mohon pilih tipe antara pemasukan dan pengeluaran\n");
            }
        }
        else{
            printf("Input yang kamu masukkan salah\n");
            }
        }
        else if(strcmp(argv[1],"--laporan")==0){
            if(eksporLaporan(data,jumlah)==1){
                printf("Ekspor Berhasil\n");
                }
                else{
                    printf("Ekspor gagal\n");
                }
        }
        else if(strcmp(argv[1],"--help")==0){
            tampilBantuan();
        }
        else{
            printf("Mohon masukin intruksi yang jelas, untuk melihat instruksi bisa gunakan perintah --help\n");
        }
    }
    return 0;
}
