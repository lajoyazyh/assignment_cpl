#include<stdio.h>
#include<string.h>
void mystrcat(char *a , char *b , int len){
    char *temp;
    char t[1005] = {0};
    temp = t;
    strcpy(temp , b);
    for(int i = 0 ; i <= len ; i++){
        *(temp + (len - i)) = '\0';
        if(strcmp(a + i , temp) == 0){
            strcpy(a + len , b + len - i);
            return;
        }
    }
    return;
}
int main(){
    int T;
    scanf("%d" , &T);
    for(int i = 1 ; i <= T ; i++){
        char *s1;
        char *s2;
        char array1[2005] = {0};
        s1 = array1;
        char array2[1005] = {0};
        s2 = array2;        
        scanf("%s" , s1);
        scanf("%s" , s2);
        int len1 = strlen(s1);
        mystrcat(s1 , s2 , len1);
        printf("%s\n" , s1);
    }
    return 0;
}