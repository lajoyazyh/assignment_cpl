#include<stdio.h>
int main(){
    int A[100][100] = {0};
    int B[100][100] = {0};
    int C[100][100] = {0};

    int m , n , p;
    scanf("%d%d%d" , &m , &n , &p);
    
    for(int i = 0 ; i <= m - 1 ; i++){
        for(int j = 0 ; j <= n - 1 ; j++){
            scanf("%d" , &A[i][j]);
        }
    }
    for(int i = 0 ; i <= n - 1 ; i++){
        for(int j = 0 ; j <= p - 1 ; j++){
            scanf("%d" , &B[i][j]);
        }
    }

    for(int x = 0 ; x <= m - 1 ; x++){
        for(int y = 0 ; y <= p - 1 ; y++){
            int sum = 0;
            for(int q = 0 ; q <= n - 1 ; q++){
                sum += A[x][q] * B[q][y];
            }
            C[x][y] = sum;
        }
    }

    for(int x = 0 ; x <= m - 1 ; x++){
        for(int y = 0 ; y <= p - 1 ; y++){
            printf("%d " , C[x][y]);
        }
        printf("\n");
    }

    return 0;
}