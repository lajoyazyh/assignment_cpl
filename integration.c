#include<stdio.h>
#include<math.h>
double list[30] = {0};
double n , p;
int flag = 0;

double f(double x ){
    double temp = 0;
    double ulti = 1;
    for(int i = 1 ; i <= n + 1 ; i++){
        double temp1 = list[i];
        for(int j = 1  ; j < i ; j++){
            temp1 *= x;
        }
        temp += temp1;
    }
    for(int i = 1 ; i <= p ; i++){
        ulti *= temp;
    }
    if(flag == 0){
        return ulti;
    }else{
        return 1 / ulti;
    }
    
    
}

double S(double a , double b){
    double mid = (a + b) / 2;
    return ((4 * f(mid) + f(a) + f(b)) * (b - a)) / 6;
}

double AS(double a , double b , double e){
    double mid = (a + b) / 2;
    double SL = S(a , mid);
    double SR = S(mid , b);
    double SM = S(a , b);
    double temp = SL + SR - SM;
    if(temp <= 15 * e && temp >= -15 * e){
        return SL + SR + temp / 15;
    }else{
        return AS(a  , mid , e / 2) + AS(mid , b , e / 2);
    }
}


int main(){
    scanf("%lf%lf" , &n , &p);
    
    if(p < 0){
        p = -p;
        flag = 1;
    }
    for(int i = 1 ; i <= n + 1 ; i++){
        scanf("%lf" , &list[i]);
    }
    double a , b;
    scanf("%lf%lf" , &a , &b);

   
    printf("%lf" , AS(a, b , 0.0001));
    
    

    return 0;
}