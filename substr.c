#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *S_p;
    S_p = malloc(100006);
    fgets(S_p , 100005 , stdin);
    int a = strlen(S_p);
    char *T_p;
    T_p = malloc(100006);
    fgets(T_p , 100005 , stdin);
    int b = strlen(T_p);
    for(int i = 0 ; i < a ; i++){
        for(int j = 0 ; j < b ; j++){
            if(j == b - 1){
                printf("%d " , i);
                break;
            }
            if(*(T_p + j) == *(S_p + i + j)){
            }else{
                break;
            }
        }
    }
    return 0;
}