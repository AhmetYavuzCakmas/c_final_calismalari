#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kitapBilgisiOku(char (*isimler)[21], int *id, int adet);
void kitapBilgisiYazdir(char (*isimler)[21],int *id, int adet);
void kitapSorgula(char (*isimler)[21], int *id, int adet, int sorguId);

int main()
{
    char isimler[10][21];
    int id[10], adet, sorguId;

    printf("Kitap sayisi giriniz: ");
    scanf("%d",&adet);
    getchar();

    if (adet <= 0 || adet > 10) {
        printf("Gecersiz kitap sayisi!\n");
    }

    printf("Kitap bilgilerini giriniz: \n");
    kitapBilgisiOku(isimler,id,adet);

    printf("Kitap bilgileri: \n");
    kitapBilgisiYazdir(isimler,id,adet);

    printf("Sorgulamak istediðiniz kitap ID'sini giriniz: ");
    scanf("%d",&sorguId
          );

    kitapSorgula(isimler,id,adet,sorguId);


    return 0;
}

void kitapBilgisiOku(char (*isimler)[21], int *id, int adet){
    for(int i = 0;i<adet;i++){
        printf("%d. kitap icin: \n",i+1);
        printf("Isim: ");
        gets(*(isimler+i));
        printf("ID: ");
        scanf("%d",id+i);
        getchar();
    }
}


void kitapBilgisiYazdir(char (*isimler)[21],int *id, int adet){
    for(int i = 0;i<adet;i++){
        printf("Isim: %s, ID: %d\n",*(isimler+i),*(id+i));
    }
}


void kitapSorgula(char (*isimler)[21], int *id, int adet, int sorguId){
    for(int i = 0;i<adet;i++){
        if(*(id+i)==sorguId){
            printf("Sonuc: ");
            puts(*(isimler+i));
            return;
        }
    }
    printf("ID numarasina ait kisi bulunamadi");
}
