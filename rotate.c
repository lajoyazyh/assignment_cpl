#include<stdio.h>
#include<string.h>

int position[5] = {0};
int ground  = 1;
int gesture = 1;

void W(int a, int b , int c){   
        if(ground == 1){
            position[4] = position[3];
            position[3] -= c;
            if(gesture == 1){
                ground = 2;
                gesture = 1;
            }else{
                ground = 3;
                gesture = 1;
            }
            
        }else if(ground == 2){
            position[4] = position[3];
            position[3] -= a;
            if(gesture == 1){
                ground = 1;
                gesture = 1;
            }else{
                ground = 3;
                gesture = 2;
            }
        }else if(ground == 3){
            position[4] = position[3];
            position[3] -= b;
            if(gesture == 1){
                ground = 1;
                gesture = 2;
            }else{
                ground = 2;
                gesture = 2;
            }
        }  
}

void S(int a, int b , int c){   
        if(ground == 1){
            position[3] = position[4];
            position[4] += c;
            if(gesture == 1){
                ground = 2;
                gesture = 1;
            }else{
                ground = 3;
                gesture = 1;
            }
            
        }else if(ground == 2){
            position[3] = position[4];
            position[4] += a;
            if(gesture == 1){
                ground = 1;
                gesture = 1;
            }else{
                ground = 3;
                gesture = 2;
            }
        }else if(ground == 3){
            position[3] = position[4];
            position[4] += b;
            if(gesture == 1){
                ground = 1;
                gesture = 2;
            }else{
                ground = 2;
                gesture = 2;
            }
        }  
}

void A(int a, int b , int c){   
        if(ground == 1){
            position[2] = position[1];
            position[1] -= c;
            if(gesture == 1){
                ground = 3;
                gesture = 2;
            }else{
                ground = 2;
                gesture = 2;
            }
            
        }else if(ground == 2){
            position[2] = position[1];
            position[1] -= a;
            if(gesture == 1){
                ground = 3;
                gesture = 1;
            }else{
                ground = 1;
                gesture = 2;
            }
        }else if(ground == 3){
            position[2] = position[1];
            position[1] -= b;
            if(gesture == 1){
                ground = 2;
                gesture = 1;
            }else{
                ground = 1;
                gesture = 1;
            }
        }  
}

void D(int a, int b , int c){   
        if(ground == 1){
            position[1] = position[2];
            position[2] += c;
            if(gesture == 1){
                ground = 3;
                gesture = 2;
            }else{
                ground = 2;
                gesture = 2;
            }
            
        }else if(ground == 2){
            position[1] = position[2];
            position[2] += a;
            if(gesture == 1){
                ground = 3;
                gesture = 1;
            }else{
                ground = 1;
                gesture = 2;
            }
        }else if(ground == 3){
            position[1] = position[2];
            position[2] += b;
            if(gesture == 1){
                ground = 2;
                gesture = 1;
            }else{
                ground = 1;
                gesture = 1;
            }
        }  
}

int main(){
    int a , b , c;
    scanf("%d%d%d" , &a , &b , &c);
    position[2] = b;
    position[4] = a;
    getchar();
    char operation[10000];
    scanf("%s" , operation);
    for(int i = 0 ; i < strlen(operation) ; i++){
        if(operation[i] == 'W'){
            W(a , b , c);
        }else if(operation[i] == 'S'){
            S(a , b , c);
        }else if(operation[i] == 'A'){
            A(a , b , c);
        }else if(operation[i] == 'D'){
            D(a , b , c);
        }
    }

    printf("%d %d %d %d" , position[3] , position[4] , position[1] , position[2]);
    return 0;
}


