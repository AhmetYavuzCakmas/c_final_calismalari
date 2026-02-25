#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aracBilgisiOku(char (*isimler)[21], char (*plakalar)[10], int boyut);
void aracBilgisiYazdir(char (*isimler)[21], char (*plakalar)[10], int boyut);
void aracSorgula(char (*isimler)[21], char (*plakalar)[10], int boyut,char* sorguPlaka);

int main()
{
    char isimler[10][21];
    char sorguPlaka[10];
    char plakalar[10][10], boyut;

    printf("Arac sayisini giriniz: ");
    scanf("%d",&boyut);
    getchar();

    if (boyut <= 0 || boyut > 10) {
        printf("Gecersiz arac sayisi!\n");
    }

    printf("Arac bilgilerini giriniz: \n");
    aracBilgisiOku(isimler,plakalar,boyut);

    printf("Arac bilgileri: \n");
    aracBilgisiYazdir(isimler, plakalar, boyut);

    printf("Sorgulamak istediginiz plaka numarasini giriniz: ");
    gets(sorguPlaka);
    aracSorgula(isimler,plakalar,boyut,sorguPlaka);




    return 0;
}

void aracBilgisiOku(char (*isimler)[21], char (*plakalar)[10], int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%d. arac icin: \n",i+1);
        printf("Isim: ");
        gets(*(isimler+i));
        printf("plaka: ");
        gets(*(plakalar+i));
    }
}

void aracBilgisiYazdir(char (*isimler)[21], char (*plakalar)[10], int boyut){
    for(int i = 0;i<boyut;i++){
        printf("Isim: ");
        puts(*(isimler + i));
        printf("Plaka: ");
        puts(*(plakalar + i));
    }

}

void aracSorgula(char (*isimler)[21], char (*plakalar)[10], int boyut,char* sorguPlaka){
    for (int i = 0; i < boyut; i++) {
        if (strcmp(*(plakalar + i), sorguPlaka) == 0) {
            printf("Sonuc: %s\n", *(isimler + i));
            return;
        }
    }
    printf("Sonuc: Arac bulunamadi\n");
}



