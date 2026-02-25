#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void diziOku(int*, int);
void diziYazdir(int*, int);
void diziyiIkiyeKatla(int*, int);


int main()
{
    int dizi[20];
    int boyut;

    printf("Enter size of array:\n");
    scanf("%d",&boyut);

    if(boyut<=0 || boyut>20){
        printf("Gecersiz boyut");
    }

    diziOku(dizi,boyut);
    printf("Dizi: \n");
    diziYazdir(dizi,boyut);
    diziyiIkiyeKatla(dizi,boyut);
    printf("Iki katina cikarilmis dizi: \n");
    diziYazdir(dizi,boyut);



    return 0;
}


void diziOku(int* dizi, int boyut){

    int* array1[boyut];
    printf("enter number of array: \n");

    for(int i = 0;i<boyut;i++){
         scanf("%d",(dizi+i));

    }
}

void diziYazdir(int* dizi,int boyut){
    for(int i =0;i<boyut;i++){
        printf("%d\n",*(dizi+i));
    }
    printf("\n");
}

void diziyiIkiyeKatla(int* dizi, int boyut){
    for(int i=0;i<boyut;i++){
        *(dizi+i)*=2;
    }
}
