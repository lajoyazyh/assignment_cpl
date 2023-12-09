#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* interleaveString(char* a , char* b , int d1 , int d2 , int size){
    int Size = size;
    char* c = malloc(2005);
    int len1 = strlen(a);
    int len2 = strlen(b);
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    while(size > 0){
        if(p1 >= len1 && p2 >= len2) break;
        int counta = 0;
        int countb = 0;

        for(int i = 1 ; i <= d1 && p1 < len1 ; i++){
            *(c + (p3++)) = *(a + (p1++));
            counta++;
        }
        for(int i = 1 ; i <= d2 && p2 < len2 ; i++){
            *(c + (p3++)) = *(b + (p2++));
            countb++;
        }
        size -= (counta + countb);
    }
    *(c + Size - 1) = '\0';
    return c;
}



int main(){
    int T;
    scanf("%d" , &T);
    getchar();
    for(int i = 1 ; i <= T ; i++){
        char array1[1003] = {0};
        char* s1 = array1;
        char array2[1003] = {0};
        char* s2 = array2;
        while((* s1++ = getchar()) != ';');
        *(s1 - 1) = '\0';
        s1 = s1 - strlen(array1) - 1;
        while((* s2++ = getchar()) != ';');
        *(s2 - 1) = '\0';
        s2 = s2 - strlen(array2) - 1;
        int d1;
        int d2;
        scanf("%d" , &d1);
        getchar();
        scanf("%d" , &d2);
        getchar();
        int size;
        scanf("%d" , &size);
        getchar();


        char* s3 = interleaveString(s1 , s2 , d1 , d2 , size);

        printf("%s\n" , s3);
    }
    return 0;
}