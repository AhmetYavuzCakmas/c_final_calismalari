#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kelimeDizisiOku(char* message[], int boyut);
void kelimeDizisiYazdir(char* message[], int boyut);
void toplamUzunluk(char* message[], int boyut);

int main()
{

    char* message[100];
    int boyut;


    puts("how many words will you enter: ");
    scanf("%d",&boyut);

    kelimeDizisiOku(message, boyut);

    printf("original sentence: \n");
    kelimeDizisiYazdir(message, boyut);

    printf("\nlengths of words: \n");
    toplamUzunluk(message,boyut);

    return 0;
}

void kelimeDizisiOku(char* message[], int boyut){
    char buffer[100];
    for(int i = 0;i<boyut;i++){
        printf("kelime %d:  ",i+1);
        scanf("%s",buffer);
        message[i] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
        strcpy(message[i],buffer);
    }

}

void kelimeDizisiYazdir(char* message[], int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%s ",message[i]);
    }
}

void toplamUzunluk(char* message[], int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%s kelimesinin uzunlugu: %lu\n",message[i],strlen(message[i]));
    }
}

