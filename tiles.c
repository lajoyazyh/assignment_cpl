#include<stdio.h>
int count = 1;
int chart(int x){
    if(x == 1){
        return 1;
    }else if(x == 2){
        return 2;
    }else{
        return chart(x - 1) + chart(x - 2);
    }
}



int main(){

    int n; 
    scanf("%d" , &n);
    printf("%d" , chart(n));




    return 0;
}