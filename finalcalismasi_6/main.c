#include <stdio.h>
#include <stdlib.h>

// Fonksiyon prototipleri
void diziOku(int*, int);
void diziYazdir(int*, int);
void esikFiltrele(int*, int, int*, int*, int);
int filtreToplami(int*, int); // Ýsim tutarlýlýðý saðlandý

int main() {
    int anaDizi[10], filtreDizi[10];
    int boyut, filtreBoyut = 0, esik;

    printf("dizi boyutunu girin: ");
    scanf("%d", &boyut);

    if (boyut <= 0 || boyut > 10) {
        printf("Gecersiz boyut!\n");
        exit(1); // Hata durumunda program sonlandýr
    }

    printf("esik degerini giriniz: ");
    scanf("%d", &esik);

    diziOku(anaDizi, boyut);
    printf("Ana dizi: \n");
    diziYazdir(anaDizi, boyut);

    for (int i = 0; i < 10; i++) {
        *(filtreDizi + i) = 0; // Tüm elemanlarý sýfýrla
    }

    esikFiltrele(anaDizi, boyut, filtreDizi, &filtreBoyut, esik);

    printf("Filtrelenmis dizi (boyut %d): ", filtreBoyut); // Çýktý formatý düzeltildi
    diziYazdir(filtreDizi, filtreBoyut);

    printf("Filtrelenmis dizi toplami: %d\n", filtreToplami(filtreDizi, filtreBoyut));

    return 0;
}

void diziOku(int* dizi, int boyut) {
    printf("enter numbers: ");
    for (int i = 0; i < boyut; i++) {
        scanf("%d", (dizi + i));
    }
}

void diziYazdir(int* dizi, int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", *(dizi + i));
    }
    printf("\n");
}

void esikFiltrele(int* anaDizi, int boyut, int* filtreDizi, int* filtreBoyut, int esik) {
    int sayac = 0;
    for (int i = 0; i < boyut; i++) {
        if (*(anaDizi + i) > esik) {
            *(filtreDizi + sayac) = *(anaDizi + i);
            sayac++; // Sayacý artýr
        }
    }
    *filtreBoyut = sayac; // Filtre dizisinin boyutunu güncelle
}

int filtreToplami(int* dizi, int boyut) {
    int toplam = 0;
    for (int i = 0; i < boyut; i++) {
        toplam += *(dizi + i); // Doðru indekse eriþ
    }
    return toplam;
}
