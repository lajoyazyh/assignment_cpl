#include<stdio.h>
int main(){
    int n;
    scanf("%d" , &n);
    getchar();
    char str[1005];
    for(int i = 0 ; i < n ; i++){
        scanf("%c" , &str[i]);
    }

    int count[55] = {0};
    for(int i = 0 ; i < n ; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            count[str[i] - 'a']++;
        }else{
            count[str[i] - 'A' + 26]++;
        }
    }

    int max = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(count[i] > max){
            max = count[i];
        }
        if(count[i + 26] > max){
            max = count[i +26];
        }
    }

    for(int c = 1 ; c <= max + 2 ; c++){
        int rank = 0;
        for(int i = 0 ; i < 26 ; i++){
            int count2 = 0;
            for(int j = i ; j < 26 ; j++){
                if(rank != 0 && (count[i - 1] != 0 || count[i + 25] != 0) && (count[j] != 0 || count[j + 26]) && count2 == 0){
                    if(c == max + 1){
                        printf("-");
                    }else{
                        printf(" ");
                    } 
                    count2++;    
                }
            }

            if(count[i] != 0){
                if(c <= max - count[i]){
                    printf(" ");
                }else if(c > max - count[i] && c <= max){
                    printf("=");
                }else if(c == max + 1){
                    printf("-");
                }else{
                    printf("%c" , i + 'a');
                }
                rank++;
            }
            if(count[i + 26] != 0){
                if(c <= max - count[i + 26]){
                    printf(" ");
                }else if(c > max - count[i + 26] && c <= max){
                    printf("=");
                }else if(c == max + 1){
                    printf("-");
                }else{
                    printf("%c" , i + 'A');
                }
                rank++;
            }

        }
        printf("\n");
    }



    return 0;
}