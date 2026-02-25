#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kargoBilgisiOku(char (*isimler)[21],int* numaralar, int boyut);
void kargoBilgisiYazdir(char (*isimler)[21], int* numaralar, int boyut);
void kargoSorgula(char (*isimler)[21],int* numaralar, int boyut,int sorguNumarasi);

int main()
{
    int boyut,sorguNumarasi;
    int* numaralar[10];
    char* isimler[10][20];

    printf("Kargo sayisini giriniz: ");
    scanf("%d",&boyut);
    getchar();

    if (boyut <= 0 || boyut > 10) {
        printf("Gecersiz boyut!\n");
        exit(1);
    }

    printf("Kargo bilgilerini giriniz: \n");
    kargoBilgisiOku(isimler,numaralar,boyut);

    printf("Kargo bilgileri: \n");
    kargoBilgisiYazdir(isimler,numaralar,boyut);

    printf("Sorgulamak istediðiniz kargo numarasini giriniz: ");
    scanf("%d",&sorguNumarasý);
    kargoSorgula(isimler,numaralar,boyut,sorguNumarasi);



    return 0;
}

void kargoBilgisiOku(char (*isimler)[21],int* numaralar, int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%d. kargo için: \n",i+1);
        printf("Isim: ");
        gets(*(isimler+i));
        printf("\nNumara: ");
        scanf("%d",numaralar+i);
        getchar();
    }
}

void kargoBilgisiYazdir(char (*isimler)[21], int* numaralar, int boyut){
    for(int i = 0;i<boyut;i++){
        printf("Isim: %s, Numara: %d\n",*(isimler+i),*(numaralar+i));
    }
}

void kargoSorgula(char (*isimler)[21],int* numaralar, int boyut,int sorguNumarasý){
    for(int i = 0;i<boyut;i++){
        if(*(numaralar +i )==sorguNumarasý){
            printf("Sonuc: %s\n",*(isimler+i));
            return;
        }
    }
    printf("Sonuc: Gonderi bulunamadý");


}
