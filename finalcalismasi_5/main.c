#include <stdio.h>
#include <stdlib.h>

void diziOku(int*, int);
void diziYazdir(int*, int);
void gruplaraAyir(int*,int,int*,int*,int*,int*);
int diziToplami(int*, int);

int main()
{
    int anaDizi[10],ciftIndis[10],tekIndis[10];
    int boyut, ciftBoyut=0,tekBoyut=0;

    printf("Dizi boyutunu girin: ");
    scanf("%d",&boyut);

    if(boyut<=0||boyut>10){
        printf("gecersiz boyut!\n");
    }

    diziOku(anaDizi,boyut);
    printf("Anadizi: ");
    diziYazdir(anaDizi,boyut);

    for(int i=0;i<10;i++){
        *(ciftIndis + i) = 0;
        *(tekIndis + i) = 0;

    }

    gruplaraAyir(anaDizi,boyut,ciftIndis,tekIndis,&ciftBoyut,&tekBoyut);

    printf("cift indisli elemanlar(boyut %d): ",ciftBoyut);
    diziYazdir(ciftIndis,ciftBoyut);

    printf("tek indisli elemanlar(boyut %d): ",tekBoyut);
    diziYazdir(tekIndis,tekBoyut);


    printf("Cift indisli elemanlar toplami: %d\n", diziToplami(ciftIndis, ciftBoyut));
    printf("Tek indisli elemanlar toplami: %d\n", diziToplami(tekIndis, tekBoyut));


    return 0;
}

void diziOku(int* dizi,int boyut){
    printf("dizi elemanlarini giriiz: ");
    for(int i=0;i<boyut;i++){
        scanf("%d",(dizi+i));
    }
}

void diziYazdir(int* dizi,int boyut){
    for(int i =0;i<boyut;i++){
        printf("%d ",*(dizi+i));
    }
    printf("\n");
}

void gruplaraAyir(int* anaDizi,int boyut,int* ciftIndis,int* tekIndis,int* ciftBoyut,int* tekBoyut){
    *ciftBoyut = (boyut+1)/2;
    *tekBoyut = boyut/2;

    int ciftSayac = 0,tekSayac =0;
    for(int i=0;i<boyut;i++){
        if(i%2==0){
            *(ciftIndis + ciftSayac) = *(anaDizi + i);
            ciftSayac++;
        }else{
            *(tekIndis + tekSayac) = *(anaDizi + i);
            tekSayac++;
        }
    }
}

int diziToplami(int* dizi,int boyut){
    int toplam = 0;
    for(int i = 0;i<boyut;i++){
        toplam += *(dizi+i);
    }
    return toplam;
}

