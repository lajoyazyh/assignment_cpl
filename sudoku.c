#include<stdio.h>
int main(){
    int sukodu[9][9] = {0};
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            scanf("%d" , sukodu[i][j]);
        }
    }

    int tell = 1;
    // for(int i = 0 ; i < 9 ; i++){
    //     for(int j = 0 ; j < 9 ; j++){
    //         if(sukodu[i][j] + '0' >= '1' && sukodu[i][j] + '0' <= '9'){
    //             continue;
    //         }else{
    //             printf("NO");
    //             return 0;
    //         }
    //     }
    // }
    for(int i = 0 ; i < 9 ; i++){
        int sum1 = 0;
        int accu1 = 1;
        int sum2 = 0;
        int accu2 = 1;
        for(int j = 0 ; j <= 9 ; j++){
            sum1 += sukodu[i][j];
            accu1 = accu1 * sukodu[i][j];
            sum2 += sukodu[j][i];
            accu2 = accu2 * sukodu[j][i];
        }
        if((sum1 == 45 && accu1 == 362880) && (sum2 == 45 && accu2 == 362880)){
            continue;
        }else{
            printf("NO");
            return 0;
        }
    }

    for(int i = 0 ; i < 9 ; i++){
        int sum1 = 0;
        int accu1 = 1;
        int sum2 = 0;
        int accu2 = 1;
        for(int j = 0 ; j <= 9 ; j++){
            sum1 += sukodu[i][j];
            accu1 = accu1 * sukodu[i][j];
            sum2 += sukodu[j][i];
            accu2 = accu2 * sukodu[j][i];
        }
        if((sum1 == 45 && accu1 == 362880) && (sum2 == 45 && accu2 == 362880)){
            continue;
        }else{
            printf("NO");
            return 0;
        }
    }



    return 0;
}