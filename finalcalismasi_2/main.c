#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void diziDoldur(int*, int);
void diziYaz(int*,int);
void solaKaydir(int*, int);
int main()
{
    int dizi[10];
    int boyut;

    printf("Enter length of array: \n");
    scanf("%d",&boyut);

    if(boyut<=0 || boyut>15){
        printf("Gecersiz boyut");
    }

    diziDoldur(dizi,boyut);
    printf("dizi: \n");
    diziYaz(dizi,boyut);
    solaKaydir(dizi,boyut);
    printf("sola kaydirilmis dizi: ");
    diziYaz(dizi,boyut);

    return 0;
}

void diziDoldur(int* dizi, int boyut){
    printf("enter numbers: \n");
    for(int i = 0;i<boyut;i++){
        scanf("%d",(dizi+i));
    }
    printf("\n");

}

void diziYaz(int* dizi,int boyut){
    for(int i=0;i<boyut;i++){
        printf("%d ", *(dizi+i));
    }
    printf("\n");
}

void solaKaydir(int* dizi, int boyut){
    int ilk = *(dizi+0);

    for(int i =0;i<boyut-1;i++){
        *(dizi+i) = *(dizi +i+1);
    }
    *(dizi+boyut-1)=ilk;
}
