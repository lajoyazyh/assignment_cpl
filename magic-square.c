#include<stdio.h>
int main(){
    int n;
    scanf("%d" , &n);

    int x = (n + 1) / 2;
    int y = 1;
    int squ[101][101] = {0};   ////本地没那么大！故仅开101！
    squ[y][x] = 1;

    for(int i = 2 ; i <= n * n ; i++){
        
        int X = x + 1;
        int Y = y - 1;
        if(X > n) X = 1;
        if(Y < 1) Y = n;
        if(squ[Y][X] == 0){
            squ[Y][X] = i;
            x = X;
            y = Y;
            continue;
        }else{
            squ[y + 1][x] = i;
            y++;
            continue;
        }
    }

    for(int a = 1 ; a <= n ; a++){
        for(int b = 1 ; b <= n ; b++){
            printf("%d " , squ[a][b]);
        }
        printf("\n");
    }

    return 0;
}