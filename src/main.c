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
    double nominalBaru;
    char bulan[8];
    Ringkasan Total;


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
               
                break;
            case 2:
                tampilCatatan(data,jumlah);
                break;
            case 3:
                printf("Masukkan id yang mau di ubah");scanf(" %d",&id);
                printf("Masukkan Nominal: ");scanf(" %ld",&nominalBaru);
                ubahCatatan(data, jumlah, id, nominalBaru);
                simpanKeBinary(data, jumlah);
                break;
            case 4:
                printf("Masukkan id yang mau di hapus");scanf(" %d",&id);
                hapusCatatan(data,&jumlah,id);
                simpanKeBinary(data, jumlah);
                break;
            case 5:
                Total=hitungRingkasan(data,jumlah,"*");
                printf("Total Pemasukan: %.2f\nTotal Pengeluaran: %.2f\nTotal Saldo: %.2f\n",Total.pemasukan,Total.pengeluaran,Total.saldo);
                break;
            case 6:
                eksporLaporan(data,jumlah,"*");
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Input salah");
                break;
        }
    }while(pilihan!=0);
}
    else{
        if(argc==5){
            if(strcmp(argv[1],"--tambah")==0){
                double Nominal=atof(argv[4]);
                if(Nominal<=0){
                    printf("Nominal tidak Valid");
                }
                else if(strcmp(argv[2],"Pemasukan")==0){
                    strcpy(baru.tipe, argv[2]);
                    strcpy(baru.kategori, argv[3]);
                    baru.nominal = Nominal;
                    tambahCatatan(data, &jumlah, baru);
                    simpanKeBinary(data, jumlah);
                }
                else if(strcmp(argv[2],"Pengeluaran")==0){
                    strcpy(baru.tipe, argv[2]);
                    strcpy(baru.kategori, argv[3]);
                    baru.nominal = Nominal;
                    tambahCatatan(data, &jumlah, baru);
                    simpanKeBinary(data, jumlah);
                }
                else {
                    printf("Mohon pilih tipe antara pemasukan dan pengeluaran");
            }   
        }
        else if(strcmp(argv[1],"--laporan")==0){
            eksporLaporan(data,jumlah,"*");
        }
        else if(strcmp(argv[1],"--help")==0){
            tampilBantuan();
        }
        else{
            printf("Input yang kamu masukkan salah");
            }
        }
    }
    return 0;
}
