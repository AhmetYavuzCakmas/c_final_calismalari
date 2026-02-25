#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aup3(int a, int *b, int c, int *total){
    int sum;
    sum = a + *b + c;
    total = &sum;
    *(b - 1) = 10;
    *(b + 2) = 20;
    a = 14;
    c = 11;
}

int main()
{
    int a = 2, b = 3, c = 4, d = 5, e = 6, sonuc;
    float x = 3.5;

    sonuc = --a % b * c > x || d++ < e ? b++ : --c;

    printf("sonuc: %d\n", sonuc);

    printf("\n===============\n");
    printf("===============\n");


    int i = 1, j;
    for (j = 0; j < 5; j = j + 2) {
        i = (i * i) + j;
    }

    switch (i) {
        case 3:   printf("zero "); break;
        case 13:  printf("one ");
        case 175: printf("two ");
        default:  printf("default");
    }

    printf("\n===============\n");
    printf("===============\n");


    int x1 = 2, y = 6;

    while (x1 * y < 100) {
        if ((x1 + y) % 7 == 0)
            break;

        if (y % 2 != 0) {
            x1 += 2;
            y *= 2;
            continue;
        }

        y -= 1;
        x1 *= 2;
    }

    printf("%d %d\n", x1, y);

    printf("\n===============\n");
    printf("===============\n");

    int x2[] = {2, -1, 0, 7, 5};
    int *p = x2 + 2;
    int *q = p;

    printf("%d\n", *x2 - 1);
    printf("%d\n", *(x2 + 2));
    printf("%d\n", *x2 + 6 - x2[3]);
    printf("%d\n", q[-1] - *q);
    printf("%d\n", p[2] - q[0]);


    printf("\n===============\n");
    printf("===============\n");


    char *ptr;
    char aChars[10] = "Excellent";
    ptr = aChars;

    *ptr = 'V';                         // aChars[0] = 'V'
    printf("%c\n", *ptr + 3);           // önemli satýr: karakter + sayý
    printf("%c\n", *(ptr + 3));         // aChars[3] basar

    *(ptr + 1) = 'A';                   // aChars[1] = 'A'
    *(ptr + 3) = 'B';                   // aChars[3] = 'B'
    printf("String = %s\n", ptr);       // diziyi yazdýr


    printf("\n===============\n");
    printf("===============\n");

    int a1[5] = {5, 4, 3, 2, 1};
    int i1, sum = 4;

    aup3(a1[1], a1 + 2, a1[2], &sum);
    printf("sum = %d\n", sum);

    for(i1 = 0; i1 < 5; i1++)
        printf("%d ", a1);

    printf("\n===============\n");
    printf("===============\n");

   char *word = (char *)malloc(10 * sizeof(char));
    strcpy(word, "Language");

    *(word + 0) = *(word + 0) + 1;
    *(word + 2) = *(word + 2) - 1;
    *(word + 4) = 'Z';

    printf("%c\n", *word + 2);
    printf("%s\n", word);

    free(word);

    return 0;



}
