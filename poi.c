#include<stdio.h>
int f[100005] = {0};
int find(int x){

    if(f[x] == x){
        return x;
    }else{
        return find(f[x]);
    }

}

int main(){
    
    int n;
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d" , &f[i]);
    }

    for(int i = 1 ; i <= n ; i ++){
        printf("%d " , find(f[i]));
    }

    return 0;
}