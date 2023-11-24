#include<stdio.h>
int main(){

    int n , L;
    int l = 0;
    int p = 0;
    int price[10005] = {0};
    int price1[10005] = {0};
    int max[10005] = {0};
    scanf("%d%d" , &n , &L);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d" , &price[i]);
    }
    for(int i = 1 ; i <= n ; i++){
        price1[i] = price[i];
    }
    for(int i = 1 ; i <= n ; i++){
        scanf("%d" , &max[i]);
    }

    int rank[10005] = {0};
    for(int i = 1 ; i <= n ; i++){
        int tempmax = 0;
        for(int j = 1 ; j  <= n ; j++){
            if(price1[j] > tempmax){
                rank[i] = j;
                tempmax = price1[j];
            }
        }
        price1[rank[i]] = 0;
    }

    int k = 1;
    while(l < L){
        int Maxrank = rank[k];
        if(l + max[Maxrank] <= L){
            p += price[Maxrank] * max[Maxrank];
            l += max[Maxrank];
        }else{
            p += price[Maxrank] * (L - l); 
            l = L;
        }
        k++;
    }

    printf("%d" , p);




    return 0;
}