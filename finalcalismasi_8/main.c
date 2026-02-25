#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kelimeDizisiOku(char (*dizi)[21], int boyut);
void kelimeDizisiYazdir(char (*dizi)[21], int boyut);
void kisaKelimeleriFiltrele(char (*anaDizi)[21], int boyut, char* birlesikKelime, int* birlesikUzunluk, int esik);
int kisaKelimeSayisi(char (*dizi)[21], int boyut, int esik);
int main()
{
    char kelimeDizisi[10][21];
    char birlesikKelime[100] = "";
    int boyut,esik,birlesikUzunluk=0;

    printf("Kelime dizisi boyutunu girin: ");
    scanf("%d",&boyut);
    getchar();

    if (boyut <= 0 || boyut > 10) {
        printf("Gecersiz boyut!\n");
        exit(1);
    }

    printf("esik uzunlugunu giriniz: ");
    scanf("%d",&esik);
    getchar();

    printf("kelime dizisini giriniz: \n");
    kelimeDizisiOku(kelimeDizisi,boyut);
    printf("orijinal kelime dizisi: \n");
    kelimeDizisiYazdir(kelimeDizisi,boyut);

    kisaKelimeleriFiltrele(kelimeDizisi, boyut, birlesikKelime, &birlesikUzunluk,esik);

    printf("esikten kisa kelimeler birlestirildi: %s\n", birlesikKelime);
    printf("birlesik kelimenin uzunluðu: %d\n",birlesikUzunluk);
    printf("esikten kisa kelime sayisi: %d\n", kisaKelimeSayisi(kelimeDizisi, boyut, esik));



    return 0;
}

void kelimeDizisiOku(char (*dizi)[21], int boyut){
    for(int i = 0;i<boyut;i++){
        gets(*(dizi+i));
    }
}

void kelimeDizisiYazdir(char (*dizi)[21], int boyut){
    for(int i = 0;i<boyut;i++){
        puts(*(dizi+i));
    }
}

void kisaKelimeleriFiltrele(char (*anaDizi)[21], int boyut,char* birlesikKelime, int* birlesikUzunluk,int esik){
    *birlesikUzunluk = 0;
    int ilkKelime = 1;
    for(int i = 0;i <boyut;i++){
        if(strlen(*(anaDizi+i))<=esik){
            if(!ilkKelime){
                strcat(birlesikKelime, " ");
                (*birlesikUzunluk)++;
            }
            strcat(birlesikKelime,*(anaDizi+i));
            *birlesikUzunluk += strlen(*(anaDizi+i));
            ilkKelime = 0;
        }
    }
}

int kisaKelimeSayisi(char (*dizi)[21],int boyut, int esik){
    int sayac = 0;
    for(int i = 0;i<boyut;i++){
        if(strlen(*(dizi+i))<= esik){
            sayac++;
        }
    }
    return sayac;
}
