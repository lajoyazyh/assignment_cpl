#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int flag = 1;
    char* title = malloc(4097);
    fgets(title , 4097 , stdin);
    *(title + strlen(title) - 1) = '\0';
    for(int i = 0 ; i < strlen(title) ; i++){
        if(*(title + i) == ' '){
            flag = 1;
            printf("%c" , *(title + i));
        }else{
            if(flag == 0){
                if(*(title + i) >= 'a' && *(title + i) <= 'z'){
                    printf("%c" , *(title + i));                     
                }else{
                    printf("%c" , *(title + i) + 'a' - 'A');    
                }                
            }else{
                if(*(title + i) >= 'A' && *(title + i) <= 'Z'){
                    printf("%c" , *(title + i));                     
                }else{
                    printf("%c" , *(title + i) + 'A' - 'a');    
                } 
                flag = 0;
            }
        }
    }
    return 0;
}