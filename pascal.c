#include<stdio.h>
int yanghui(int a , int b){

    if(a == 1 || b == 1 || a == b) return 1;
    else{
        return yanghui(a - 1 , b - 1) + yanghui(a - 1 , b);
    }

}

int main(){

    int a , b;
    scanf("%d%d" , &a , &b);
    printf("%d" , yanghui(a , b));

    return 0;
}