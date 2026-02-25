#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void biletAl (char(*isimler)[21], int *koltuklar, int *doluSayisi);
void biletSorgula(char (*isimler)[21], int *koltuklar, int doluKoltuk, char *sorguIsim);
int kalanKoltukSayisi(int doluSayisi);
void menuGoster();

int main()
{
    char isimler[50][21];
    int koltuklar[50],doluSayisi=0;
    int secim;

    srand(time(NULL));//Rastgele sayi üretimi icin;


    while(1){
        menuGoster();
        printf("Seciminizi girin (1-4): ");
        scanf("%d",&secim);
        getchar(); //scanf sonrasi yeni satiri temizle

        switch(secim){
            case 1://bilet al
                if(doluSayisi>=50){
                    printf("Otobus dolu!\n");
                }else{
                    biletAl(isimler,koltuklar,&doluSayisi);
                }
                break;
            case 2: //bilet sorgula
                {
                    char sorguIsim[21];
                    printf("Sorgulamak istediginiz yolcu ismi giriniz: ");
                    gets(sorguIsim);
                    biletSorgula(isimler,koltuklar,doluSayisi,sorguIsim);
                }
                break;
            case 3: // kalan koltuk sayisini ogren
                printf("Kalan koltuk sayisi: %d\n",kalanKoltukSayisi(doluSayisi));
                break;
            case 4: //cikis
                printf("Program sonlandı.\n");
                return 0;
            default:
                printf("Gecersiz secim.");

        }

    }
    return 0;
}

void menuGoster(){
    printf("=== Otobus Koltuk Rezervasyon Sistemi ===");
    printf("\n\n1) Bilet al\n2) Bilet Sorgula\n3) Kalan koltuk sayisini ogren\n4) Cikis\n");
}

void biletAl(char (*isimler)[21], int *koltuklar, int *doluSayisi){
    char isim[21];
    printf("yolcu ismini giriniz: ");
    gets(isim); //gets ile isim oku

    int koltuk;
    int koltukKullanildi;
    do{
        koltuk = (rand() % 50)+1;
        koltukKullanildi = 0;
        for(int i = 0;i<*doluSayisi;i++){
            if (*(koltuklar + i) == koltuk) {
                koltukKullanildi = 1;
                break;
            }
        }
    }while(koltukKullanildi);

    strcpy(*(isimler + *doluSayisi),isim);
    *(koltuklar+ *doluSayisi) = koltuk;
    (*doluSayisi)++;
    printf("Koltuk numarasi: %d\n",koltuk);

}

void biletSorgula(char (*isimler)[21], int *koltuklar, int doluKoltuk, char *sorguIsim){
    for(int i = 0;i<doluKoltuk;i++){
        if(strcmp(*(isimler+i), sorguIsim) == 0){
            printf("Sonuc: koltuk numarasi %d\n",*(koltuklar+i));
            return;
        }
    }
    printf("Sonuc: Yolcu bulunamadi\n");
}

int kalanKoltukSayisi(int doluSayisi){
    return 50-doluSayisi;
}
