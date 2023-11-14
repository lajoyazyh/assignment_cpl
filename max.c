#include<stdio.h>
#include<math.h>
int f[100000] = {0};
int ans[100000][2] = {0};
int tempmax = 0;

void max(int l , int r){
    int Max = 0; 
    int p = 1;
    for(int i = l ; i <= r ; i++){
        if (f[i] > Max){
            Max = f[i];
            p = i;
        }
    }
    tempmax = p;
    return;
}


void find(int l , int r){
    
    if(l == r){
        ans[l][0] = l;
        ans[l][1] = r;
        return;
    }else{
        max(l , r);
        int rank = tempmax;
        ans[rank][0] = l;
        ans[rank][1] = r;
        if(l != rank){
            find(l , rank - 1);  
        } 
        if(r != rank){
            find(rank + 1 , r);  
        } 
    }
    return;
}


int main(){
    int n; 
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i++){
        scanf("%d" , &f[i]);
    }
    find(1 , n);
    for(int i = 1 ; i <= n ; i++){
        printf("%d %d\n" , ans[i][0] , ans[i][1]);
    }
    return 0;
}