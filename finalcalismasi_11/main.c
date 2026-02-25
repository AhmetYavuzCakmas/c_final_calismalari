#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void kelimeOku(char* kelimeler[], int boyut);
void enUzunKelime(char* kelimeler[], int boyut);
void yazdir(char* kelimeler[],int boyut);

int main()
{
    int boyut;
    char* kelimeler[100];

    printf("how many words will you enter? ");
    scanf("%d",&boyut);
    getchar();  // scanf'ten sonra input buffer'daki '\n' karakterini temizler


    kelimeOku(kelimeler,boyut);
    printf("original words:\n");
    yazdir(kelimeler, boyut);
    enUzunKelime(kelimeler,boyut);
    printf("modified words:\n");
    yazdir(kelimeler,boyut);

    return 0;
}

void kelimeOku(char* kelimeler[],int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%d: ",i+1);
        *(kelimeler+i)= (char*)malloc(21);
        gets(*(kelimeler +i));
    }
}

void enUzunKelime(char* kelimeler[],int boyut){
    int max = 0;
    int index = 0;
    for(int  i = 0 ;i<boyut;i++){
        int len = strlen(kelimeler[i]);
        if(len>max){
            max = len;
            index = i;
        }
    }

    for(int j = 0;j<strlen(kelimeler[index]);j++){
        kelimeler[index][j]= toupper(kelimeler[index][j]);
    }
}

void yazdir(char* kelimeler[], int boyut){
    for(int i = 0;i<boyut;i++){
        printf("%s\n",*(kelimeler+i));
    }
}
