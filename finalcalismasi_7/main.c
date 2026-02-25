#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void diziOku(int* dizi,int boyut);
void diziYazdir(int* dizi,int boyut);
void ciftTekReverse(int* dizi,int boyut, int* ciftSayisi,int* tekSayisi);
int ciftlerToplam(int* dizi, int ciftSayisi);
int main()
{
    int dizi[10];
    int boyut,ciftSayisi=0,tekSayisi = 0;

    printf("enter size of array: ");
    scanf("%d",&boyut);

    if (boyut <= 0 || boyut > 10) {
        printf("Gecersiz boyut!\n");
    }

    diziOku(dizi,boyut);
    printf("original array: \n");
    diziYazdir(dizi,boyut);

    ciftTekReverse(dizi,boyut,&ciftSayisi,&tekSayisi);

    printf("displaced array: \n");
    diziYazdir(dizi,boyut);

    printf("Cift sayilarin sayisi: %d\n", ciftSayisi);
    printf("Tek sayilarin sayisi: %d\n", tekSayisi);
    printf("Cift sayilarin toplami: %d\n", ciftlerToplami(dizi, ciftSayisi));

    return 0;
}

void diziOku(int* dizi, int boyut){
    printf("enter  odd and even numbers: \n");
    for(int i = 0;i<boyut;i++){
        scanf("%d",(dizi+i));
    }
    printf("\n");
}

void diziYazdir(int* dizi,int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%d ",*(dizi+i));
    }
}

void ciftTekReverse(int* dizi,int boyut, int* ciftSayisi, int* tekSayisi){
    int* geciciDizi = (int*)malloc(boyut *sizeof(int));
    int ciftSayac =0,tekSayac = boyut-1;

    for(int i = 0;i<boyut;i++){
        if(*(dizi+i)%2 ==0){
            *(geciciDizi + ciftSayac) = *(dizi+i);
            ciftSayac++;
        }else{
            *(geciciDizi + tekSayac)=*(dizi +i);
            tekSayac--;
        }
    }
    *ciftSayisi = ciftSayac;
    *tekSayisi = boyut - ciftSayac;

    for(int i = 0;i<boyut;i++){
        *(dizi +i)= *(geciciDizi + i);
    }

    free(geciciDizi);

}

int ciftlerToplami(int* dizi,int ciftSayisi){
    int toplam = 0;
    for(int i = 0;i<ciftSayisi;i++){
        toplam += *(dizi +i);
    }
    return toplam;
}
