#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void diziAl(int*, int);
void diziYaz(int*, int);
void reversecopying(int*,int*,int);
int main()
{
    int kaynak[12], hedef[12], boyut;

    printf("enter length of array: \n");
    scanf("%d",&boyut);
    if(boyut<0 ||boyut>=12){
        printf("gecersiz boyut");
    }

    diziAl(kaynak,boyut);
    printf("kaynak dizi: \n");
    diziYaz(kaynak,boyut);
    reversecopying(kaynak,hedef,boyut);
    printf("hedef dizi(tersten): \n");
    diziYaz(hedef,boyut);



    return 0;
}

void diziAl(int* dizi, int boyut){
    printf("enter numbers: \n");
    for(int i=0;i<boyut;i++){
        scanf("%d",(dizi+i));
    }
}

void diziYaz(int* dizi, int boyut){
    for(int i=0;i<boyut;i++){
        printf("%d ",*(dizi+i));
    }
    printf("\n");
}

void reversecopying(int* source, int* hedef,int boyut){
    for(int i = 0;i<boyut;i++){
        *(hedef+i)=*(source +(boyut-1-i));
    }

}
