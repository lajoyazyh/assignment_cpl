#include<stdio.h>

int search(int a[] , int c , int min , int low , int high){
    
    while(low <= high){
        int middle = (low + high) / 2;
        
        if(c - a[middle] >= 0){
            if(c - a[middle] < min){
                min = c - a[middle];
            }
            return search(a , c , min , middle + 1 , high);
        }else if(c - a[middle] < 0){
            return search(a , c , min , low , middle - 1);
        }
    }
    return min;
}    

int main(){
    int n , m , t;
    int a[1000005] = {0};
    int b[1000005] = {0};
    scanf("%d%d%d" , &n , &m , &t);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d" , &a[i]);
    }
    for(int i = 1 ; i <= m ; i ++){
        scanf("%d" , &b[i]);
    }
    int min = t + 1;
    for(int i = 1 ; i <= m ; i ++){
        if(b[i] + a[1] > t){
            continue;
        }
        int temp = search(a , t - b[i] , t - b[i], 1 , n);
        if(temp < min){
            min = temp;
        }
    }

    if(min == t + 1){
        printf("-1");
        return 0;
    }
    printf("%d" , min);

    return 0;
}