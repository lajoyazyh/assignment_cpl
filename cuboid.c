#include<stdio.h>
char canvas[10000][100000] = {0};
void top(int x , int y){    //画长方体的顶端（单位）
    canvas[x][y] = '+';
    canvas[x][y - 2] = '+';
    canvas[x - 2][y] = '+';
    canvas[x - 2][y + 2] = '+';

    canvas[x][y - 1] = '-';
    canvas[x - 2][y + 1] = '-';

    canvas[x - 1][y - 1] = '/';
    canvas[x - 1][y + 1] = '/';
}
void front(int x , int y){    //画长方体的前端（单位）
    canvas[x][y] = '+';
    canvas[x][y - 2] = '+';
    canvas[x + 2][y] = '+';
    canvas[x + 2][y - 2] = '+';

    canvas[x][y - 1] = '-';
    canvas[x + 2][y - 1] = '-';

    canvas[x + 1][y] = '|';
    canvas[x + 1][y - 2] = '|';
}
void side(int x , int y){    //画长方体的右端（单位）
    canvas[x][y] = '+';
    canvas[x - 2][y + 2] = '+';
    canvas[x][y + 2] = '+';
    canvas[x + 2][y] = '+';

    canvas[x - 1][y + 1] = '/';
    canvas[x + 1][y + 1] = '/';

    canvas[x + 1][y] = '|';
    canvas[x - 1][y + 2] = '|';
}
void cuboid(int a , int b , int c){
    for(int i = 0 ; i <= 2 * b - 2 ; i += 2){  //画长方体的上面
        for(int j = 0 ; j <= 2 * a - 2; j += 2){
            top(2 * b - i , 2 * a + i - j);
        }
    }
    for(int i = 0 ; i <= 2 * c - 2 ; i += 2){  //画长方体的前面
        for(int j = 0 ; j <= 2 * a - 2 ; j += 2){
            front(2 * b + i , 2 * a - j);
        }
    }
    for(int i = 0 ; i <= 2 * b - 2 ; i += 2){  //画长方体的右面
        for(int j = 0 ; j <= 2 * c - 2 ; j += 2){
            side(2 * b - i + j , 2 * a + i);
        }
    }
}
int main(){   
    int T = 0;
    scanf("%d" , &T);
    for(int i = 1 ; i <= T ; i++){
        int a , b , c;
        scanf("%d%d%d" , &a , &b , &c);
        cuboid(a , b , c);

        for(int i = 0 ; i <= 2 * c + 2 * b ; i++){
            for(int j = 0 ; j <= 2 * a + 2 * b ; j++){
                if(canvas[i][j] != 0){
                    printf("%c" , canvas[i][j]);
                    canvas[i][j] = 0;
                }else{
                    printf(" ");
                }
            
            }
            printf("\n");
        }
    }  
}