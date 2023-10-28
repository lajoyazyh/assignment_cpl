#include<stdio.h>
int main(){
    int n , t;
    scanf("%d%d" , &n , &t);

    int sum = 0;
    int add = 0;
    for(int i = 1 ; i <= n ; i++){
        add = add * 10 + t;
        sum += add;
    }

    printf("%d" , sum);



    return 0;
}