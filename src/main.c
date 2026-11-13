#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"include/fungsi.h"

int main(int argc, char*argv[]){
    int pilihan;
    if(argc == 1){
        printf("========= PILIHAN MENU =========");
        printf("Tipe: ");
        switch(pilihan){

        }
    }
    else{
        if(argc==5){
            if(strcmp(argv[1],"--tambah")==0){
                int Nominal=atol(argv[4]);
                if(Nominal<=0){
                    printf("");
                }
            simpanTransaksi(argv[2],argv[3],Nominal);
            }   
        }
        else if(strcmp(argv[1],"--laporan")==0){
            
        }
        else{
            printf("Input yang kamu masukkan salah");
        }
    }


    return 0;
}