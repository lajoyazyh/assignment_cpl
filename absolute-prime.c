#include<stdio.h>
#include<math.h>
int reverse(int a){
    int thou = a / 1000;
    a -= thou * 1000;
    int hun = a / 100;
    a -= hun * 100;
    int ten = a / 10;
    a -= ten * 10;
    if(thou){
        return 1000 * a + 100 * ten + 10 * hun + thou;
    }else if(hun){
        return 100 * a  + 10 * ten + hun;
    }else if(ten){
        return 10 * a + ten;
    }else{
        return a;
    }
}

int is_prime(int b){
    for(int i = 2 ; i <= sqrt(b + 1) ; i++){
        if(b % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){

    int n; 
    scanf("%d" , &n);
    int count = 0;
    for(int i = 2 ; i <= n ; i++){
        if(is_prime(reverse(i)) == 1 && is_prime(i) == 1){
            count++;
        }
    }

    printf("%d" , count);





    return 0;
}