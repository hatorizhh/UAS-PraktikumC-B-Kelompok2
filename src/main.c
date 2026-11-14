#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"../include/fungsi.h"

int main(int argc, char*argv[]){
    CatatanKeuangan baru;

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(baru.tanggal, sizeof(baru.tanggal), "%Y-%m-%d", tm_info);
    
    int pilihan=0;
    if(argc == 1){
        printf("========= PILIHAN MENU =========");
        printf("Tipe:\n1. Tambah\n2. Laporan\n3. Help");
        scanf(" %d",&pilihan);
        switch(pilihan){   
            case 1:
                
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
    else{
        if(argc==5){
            if(strcmp(argv[1],"--tambah")==0){
                if(strcmp(argv[2],"pemasukan")==0){

                }
                if(strcmp(argv[2],"pengeluaran")==0){

                }
                double Nominal=atof(argv[4]);
                if(Nominal<=0){
                    printf("");
                }
            }   
        }
        else if(strcmp(argv[1],"--laporan")==0){
            eksporLaporan();
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