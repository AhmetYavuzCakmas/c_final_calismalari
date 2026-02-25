#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kelimeOku(char* kelimeler[], int boyut);
void tersCevir(char* kelime);
void yazdir(char* kelimeler[],int boyut);

int main()
{
    int boyut;
    char* kelimeler[100];

    printf("how many words will you enter: ");
    scanf("%d",&boyut);

    kelimeOku(kelimeler,boyut);

    printf("orijinal kelimeler: \n");
    yazdir(kelimeler, boyut);

    printf("ters cevrilen kelimeler: \n");
    for(int i = 0 ; i<boyut;i++){
        tersCevir(*(kelimeler+i));
    }

    yazdir(kelimeler,boyut);


    return 0;
}

void kelimeOku(char* kelimeler[], int boyut){
    char buffer[100];
    printf("kelimeleri giriniz: \n");

    for(int i =0; i<boyut;i++){
        printf("%d. kelime: ",i+1);
        scanf("%s",buffer);
        kelimeler[i] = (char*)malloc(strlen(buffer)+1);
        strcpy(kelimeler[i],buffer);
    }
}

void tersCevir(char* kelime){
    int len = strlen(kelime);
    for(int i= 0;i<len/2;i++){
        char gecici = kelime[i];
        kelime[i] = kelime[len-i-1];
        kelime[len-1-i]= gecici;
    }
}

void yazdir(char* kelimeler[], int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%s\n",*(kelimeler+i));
    }
}
