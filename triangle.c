#include<stdio.h>
#include<math.h>
char canvas[1000000][1000000] = {0};
void paint(int n , int x , int y){
    if(n == 1){
        canvas[x][y] = ' ';
        canvas[x][y + 1] = '/';
        canvas[x][y + 2] = '\\';
        canvas[x + 1][y] = '/';
        canvas[x + 1][y + 1] = '_';
        canvas[x + 1][y + 2] = '_';
        canvas[x + 1][y + 3] = '\\';
    }else{
        paint(n - 1 , x , y + pow(2 , n - 1));
        paint(n - 1 , x + pow(2 , n - 1) , y);
        paint(n - 1 , x + pow(2 , n - 1) , y + pow(2 , n));

    }  
}

int main(){
    int n;
    scanf("%d" , &n);
    paint(n , 1 , 1);
    for(int i = 1 ; i <= pow(2 , n) ; i++){
        if(i > 1){
            printf("\n");
        }
        for(int j = 1 ; j <= pow(2 , n + 1) ; j++){
            if(canvas[i][j] == 0){
                printf(" ");
            }
            if(canvas[i][j] == ' ' || canvas[i][j] == '/' || canvas[i][j] == '\\' || canvas[i][j] == '_'){
                printf("%c" , canvas[i][j]);
            }
        }
    }
    return 0;
}