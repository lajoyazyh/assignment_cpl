#include<stdio.h>
#include<math.h>
int radix(int a , int b , int c , int n){
    int A , B , C;
    if(a / 10 == 0){
        A = a * 1;
    }else{
        A = (a / 10) * n + (a % 10) * 1;
    }
    if(b / 10 == 0){
        B = b * 1;
    }else{
        B = (b / 10) * n + (b % 10) * 1;
    }
    if(c / 10 == 0){
        C = c * 1;
    }else{
        C = (c / 10) * n + (c % 10) * 1;
    }
    if (A * B == C){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int p , q , r;
    scanf("%d%d%d" , &p , &q , &r);
    int max = 0;
    if((p % 10) > max) max = p % 10;
    if((q % 10) > max) max = q % 10;
    if((r % 10) > max) max = r % 10;
    if((p / 10) > max) max = p / 10;
    if((q / 10) > max) max = q / 10;
    if((r / 10) > max) max = r / 10;

    for(int i = 2 ; i <= 40 ; i++){
        if(radix(p , q , r , i) == 1 && i > max){
            printf("%d" , i);
            return 0;
        }
    }

    printf("0");
    return 0;
}