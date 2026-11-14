#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"../include/fungsi.h"

int main(int argc, char*argv[]){
    CatatanKeuangan data[MAKS];
    int jumlah = muatDariBinary(data);
    int pilihan, id, i;
    int jalan = 1;
    double nominalBaru;
    char bulan[8];
    CatatanKeuangan catatan;
    Ringkasan r;
    time_t sekarang;
    struct tm *waktu;


    if(argc == 1){
        while(jalan==1){
            printf("\n=== PERSONAL EXPENSE TRACKER ===\n");
            printf("1. Tambah catatan\n");
            printf("2. Tampilkan catatan\n");
            printf("3. Ubah nominal\n");
            printf("4. Hapus catatan\n");
            printf("5. Ringkasan keuangan\n");
            printf("6. Ekspor laporan CSV\n");
            printf("0. Keluar\n");
            printf("Pilihan: ");
            scanf(" %d",&pilihan);
            switch(pilihan){   
                case 1:
                sekarang = time(NULL);
                waktu = localtime(&sekarang);
                strftime(catatan.tanggal, 11, "%Y-%m-%d", waktu);

                printf("Tanggal (YYYY-MM-DD): ");
                fgets(catatan.tanggal, sizeof(catatan.tanggal), stdin);
                for (i = 0; i < strlen(catatan.tanggal); i++) {
                    if (catatan.tanggal[i] == '\n') {
                        catatan.tanggal[i] = '\0';
                    }
                }

                printf("Kategori: ");
                fgets(catatan.kategori, sizeof(catatan.kategori), stdin);
                for (i = 0; i < strlen(catatan.kategori); i++) {
                    if (catatan.kategori[i] == '\n') {
                        catatan.kategori[i] = '\0';
                    }
                }

                printf("Tipe (Pemasukan/Pengeluaran): ");
                fgets(catatan.tipe, sizeof(catatan.tipe), stdin);
                for (i = 0; i < strlen(catatan.tipe); i++) {
                    if (catatan.tipe[i] == '\n') {
                        catatan.tipe[i] = '\0';
                    }
                }

                printf("Nominal: ");
                if (scanf("%lf", &catatan.nominal) != 1 || catatan.nominal < 0) {
                    printf("Nominal tidak valid.\n");
                    fflush(stdin);
                } else {
                    getchar();
                    if (strcmp(catatan.tipe, "Pemasukan") != 0 && strcmp(catatan.tipe, "Pengeluaran") != 0) {
                        printf("Tipe harus Pemasukan atau Pengeluaran.\n");
                    } else {
                        tambahCatatan(data, &jumlah, catatan);
                        simpanKeBinary(data, jumlah);
                    }
                }
                break;
            case 2:

                break;
            case 3:

                break;
            default:
                printf("Input salah");
                return 1;
        }
    }
}
    else{
        if(argc==5){
            if(strcmp(argv[1],"--tambah")==0){
                double Nominal=atof(argv[4]);
                if(strcmp(argv[2],"Pemasukan")==0){
                    
                }
                else if(strcmp(argv[2],"Pengeluaran")==0){
                    
                }
                if(Nominal<=0){
                    printf("Nominal tidak Valid");
                }
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


    return 0;
}