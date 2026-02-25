#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonksiyon prototipleri
void kargoBilgisiOku(char (*isimler)[21], int *numaralar, int n);
void kargoBilgisiYazdir(char (*isimler)[21], int *numaralar, int n);
void kargoSorgula(char (*isimler)[21], int *numaralar, int n, int sorguNumarasi);

int main() {
    char isimler[10][21]; // 10 isim, her biri en fazla 20 karakter
    int numaralar[10]; // 10 kargo numarasý
    int n, sorguNumarasi;

    // Kargo sayýsýný al
    printf("Kargo sayisini girin: ");
    scanf("%d", &n);
    getchar(); // scanf sonrasý yeni satýrý temizle

    // Hata kontrolü
    if (n <= 0 || n > 10) {
        printf("Gecersiz kargo sayisi!\n");
        exit(1);
    }

    // Kargo bilgilerini oku
    printf("Kargo bilgilerini giriniz:\n");
    kargoBilgisiOku(isimler, numaralar, n);

    // Kargo bilgilerini yazdýr
    printf("Kargo bilgileri:\n");
    kargoBilgisiYazdir(isimler, numaralar, n);

    // Sorgulama yap
    printf("Sorgulamak istediginiz kargo numarasini girin: ");
    scanf("%d", &sorguNumarasi);
    kargoSorgula(isimler, numaralar, n, sorguNumarasi);

    // Ek sorgulama (örnek için bir tane daha)
    printf("Sorgulamak istediginiz kargo numarasini girin: ");
    scanf("%d", &sorguNumarasi);
    kargoSorgula(isimler, numaralar, n, sorguNumarasi);

    return 0;
}

void kargoBilgisiOku(char (*isimler)[21], int *numaralar, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d. kargo icin:\n", i + 1);
        printf("Isim: ");
        fgets(*(isimler + i), 21, stdin); // Pointer aritmetiði ile isim oku
        (*(isimler + i))[strcspn(*(isimler + i), "\n")] = '\0'; // Yeni satýrý kaldýr
        printf("Numara: ");
        scanf("%d", numaralar + i); // Pointer aritmetiði ile numara oku
        getchar(); // scanf sonrasý yeni satýrý temizle
    }
}

void kargoBilgisiYazdir(char (*isimler)[21], int *numaralar, int n) {
    for (int i = 0; i < n; i++) {
        printf("Isim: %s, Numara: %d\n", *(isimler + i), *(numaralar + i));
    }
}

void kargoSorgula(char (*isimler)[21], int *numaralar, int n, int sorguNumarasi) {
    for (int i = 0; i < n; i++) {
        if (*(numaralar + i) == sorguNumarasi) {
            printf("Sonuc: %s\n", *(isimler + i));
            return;
        }
    }
    printf("Sonuc: Gonderi bulunamadi\n");
}
