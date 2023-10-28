#include<stdio.h>
int main(){
    int n; 
    scanf("%d" , &n);
    int str[2005];
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &str[i]);
    }

    for(int i = n - 2 ; i >= 0 ; i--){
        if(str[i] < str[i + 1]){
            int min = str[i + 1];
            int flag = i + 1;
            for(int j = i + 2 ; j < n ; j++){
                if(str[j] > str[i] && str[j] < min){
                    min = str[j];
                    flag = j;
                }                
            }
            str[flag] = str[i];
            str[i] = min;

            int alternative[2005];
            for(int j = 1 ; j <= n - i - 1 ; j++){
                alternative[j] = str[n - j];
            }
            for(int j = 1 ; j <= n - i - 1 ; j++){
                str[i + j] = alternative[j];
            }
            
            break;
        }
    }

    for(int i = 0 ; i < n ; i++){
        printf("%d " , str[i]);
    }



    return 0;
}