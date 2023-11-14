#include<stdio.h>
int ans[1000000] = {0};

void find(int n , int min , int nfound){
    if(n == 0){
        for(int i = 0 ; i <= nfound - 1 ; i++){
            printf("%d " , ans[i]);
        }
        printf("\n");
    }
    if(n < min){
        return;
    }else{
        for(int i = min ; i <= n ; i++){
            ans[nfound] = i;
            find(n - i , i , nfound + 1);
        }
    }
}


int main(){

    int n = 0;
    scanf("%d" , &n);
    find(n , 1 , 0);

    return 0;
}