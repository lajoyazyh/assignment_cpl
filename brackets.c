#include<stdio.h>
#include <stdbool.h>
int stack[100005] = {0};
int top = 0; 

void pop() { 
        top--; 
    } 

void push(char m){
    top++;
    stack[top] = m;
}

int compare(int a , int b){
    if (a=='[' && b==']')
        return 1;
    else if (a=='(' && b==')')
        return 1;
    else if (a=='{' && b=='}')
        return 1;
    else
        return 0;
}

int islegal(char arr[] , int n){
    for(int i = 1 ; i <= n ; i++){
        if(top == 0){
            push(arr[i]);
        }else{
            if(compare(stack[top] , arr[i]) == 1){
                pop();
            }else{
                push(arr[i]);
            }
        }
    }
    if(top == 0){
        return 1;
    }else{
        return 0;
    }
    
}

int main(){
    char contents[100005] = {0};
    int ans[100005] = {0};
    int T;
    scanf("%d" , &T);
    getchar();
    for(int t = 1 ; t <= T ; t++){
        
        int n = 0;
        for(int w = 1 ; contents[w - 1] != '\n' ; w++){
            scanf("%c" , &contents[w]);
            n++;
        }
        ans[t] = islegal(contents , n - 1);
        top = 0;
    }

    for(int t = 1 ; t <= T ; t++){
        if(ans[t] == 1){
            printf("True");
        }else{
            printf("False");
        } 
        printf("\n");
    }

    return 0;
}