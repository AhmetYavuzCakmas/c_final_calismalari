#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void diziGir(int*, int);
void diziGoster(int*, int);
int ciftSayiToplami(int*, int);
int main()
{
    int dizi[15];
    int boyut;
    printf("Enter lenght of array: \n");
    scanf("%d",&boyut);

    if(boyut<0 ||boyut>=15){
        printf("gecersiz boyut");
    }

    diziGir(dizi,boyut);
    diziGoster(dizi,boyut);
    printf("Cift sayilarin toplam: %d",ciftSayiToplami(dizi,boyut));



    return 0;
}

void diziGir(int* dizi,int boyut){

    printf("enter number of array: \n");

    for(int i = 0;i<boyut;i++){
        scanf("%d",(dizi+i));
    }
    printf("\n");

}

void diziGoster(int* dizi,int boyut){
    for(int i=0;i<boyut;i++){
        printf("%d, ",*(dizi+i));
    }
    printf("\n\n");
}
int ciftSayiToplami(int* dizi, int boyut){
    int toplam = 0;
    for(int i = 0;i<boyut;i++){
        if(*(dizi+i)%2==0){
            toplam += *(dizi+i);
        }
    }
    return toplam;
}
