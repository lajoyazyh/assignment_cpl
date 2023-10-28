#include<stdio.h>
int main(){


    int n;
    scanf("%d" , &n);
    getchar();
    char map[101][101];
    char ch;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%c" , &map[i][j]);
        }
        getchar();
    }
    int vectors[8][2] = {{0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0} , {1 , 1} , {1 , -1} , {-1 , 1} , {-1 , -1}};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(map[i][j] != '*'){

            
                int count = 0;
                if(i != 0 && i != n - 1 && j != 0 && j != n - 1){
                    for(int k = 0 ; k < 8 ; k++){
                        int newI = i + vectors[k][0];
                        int newJ = j + vectors[k][1];
                        if (map[newI][newJ] == '*') {
                            count++;
                        }
                    }
                }else if(i == 0){
                    if(j == 0){
                        for(int k = 0 ; k < 5 ; k += 2){
                            int newI = i + vectors[k][0];
                            int newJ = j + vectors[k][1];
                            if (map[newI][newJ] == '*') {
                                count++;
                            }
                        }
                    }else if(j == n - 1){
                        if(map[i][j - 1] == '*'){
                            count++;
                        }
                        if(map[i + 1][j - 1] == '*'){
                            count++;
                        }
                        if(map[i + 1][j] == '*'){
                            count++;
                        }

                    }else{
                        if(map[i][j - 1] == '*'){
                            count++;
                        }
                        if(map[i + 1][j - 1] == '*'){
                            count++;
                        }
                        if(map[i + 1][j] == '*'){
                            count++;
                        }
                        if(map[i + 1][j + 1] == '*'){
                            count++;
                        }
                        if(map[i][j + 1] == '*'){
                            count++;
                        }

                    }
                }else if(i == n - 1){
                    if(j == 0){
                        if(map[i][j + 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j + 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j] == '*'){
                            count++;
                        }

                    }else if(j == n - 1){
                        if(map[i][j - 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j - 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j] == '*'){
                            count++;
                        }

                    }else{
                        if(map[i][j - 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j - 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j] == '*'){
                            count++;
                        }
                        if(map[i - 1][j + 1] == '*'){
                            count++;
                        }
                        if(map[i][j + 1] == '*'){
                            count++;
                        }

                    }
                }else{
                    if(j == 0){
                        if(map[i][j + 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j + 1] == '*'){
                            count++;
                        }
                        if(map[i + 1][j + 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j] == '*'){
                            count++;
                        }
                        if(map[i + 1][j] == '*'){
                            count++;
                        }

                    }else{
                        if(map[i][j - 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j - 1] == '*'){
                            count++;
                        }
                        if(map[i + 1][j - 1] == '*'){
                            count++;
                        }
                        if(map[i - 1][j] == '*'){
                            count++;
                        }
                        if(map[i + 1][j] == '*'){
                            count++;
                        }

                    }
                }
                map[i][j] = count + '0';
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%c" , map[i][j]);
        }
        printf("\n");
    }





    return 0;
}