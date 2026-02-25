#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void diziOku(int*, int);
void diziYaz(int*, int);
void elemanlariArtir(int*, int, int);
int main()
{
    int dizi[8];
    int boyut,artis;

    printf("enter length of array: ");
    scanf("%d",&boyut);

    if (boyut <= 0 || boyut > 8) {
        printf("Gecersiz boyut!\n");
        exit(1);
    }

    printf("artis degerini giriniz: ");
    scanf("%d",&artis);

    diziOku(dizi,boyut);
    printf("dizinin oijinali: \n");
    diziYaz(dizi,boyut);
    elemanlariArtir(dizi,boyut,artis);
    printf("artirilmis hali: \n");
    diziYaz(dizi,boyut);


    return 0;
}

void diziOku(int* dizi, int boyut){
    printf("enter numbers: \n");
    for(int i = 0;i<boyut;i++){
        scanf("%d",(dizi+i));
    }
}

void diziYaz(int* dizi,int boyut){
    for(int i=0;i<boyut;i++){
        printf("%d ",*(dizi+i));
    }
    printf("\n");
}

void elemanlariArtir(int* dizi,int boyut,int artis){
    for(int i=0;i<boyut;i++){
        *(dizi +i) += artis;
    }

}
