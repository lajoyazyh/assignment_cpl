#include<stdio.h>
#include<math.h>
int main(){
    int p;
    scanf("%x" , &p);
    int *a1 = (int *)&p;
    unsigned int *b1 = (unsigned int *)&p;
    float *c1 = (float *)&p;
    int a = *a1;
    unsigned int b = *b1;
    float c = *c1;
    printf("%d\n%u\n%.6f\n%.3e" , a , b , c , c);
    return 0;
}