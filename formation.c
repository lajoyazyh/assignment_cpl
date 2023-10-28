#include<stdio.h>
int main(){
    int m , n ;
    scanf("%d%d", &m , &n);
    getchar();
    
    char form[200][200] = {0};
    for (int i = 0 ; i < n ; i++){
        scanf("%c" , &form[0][i]);
    }
    
    for(int i = 1 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j == 0){
                if(form[i - 1][j] == '1'){
                    if(form[i - 1][j + 1] == '1'){
                        form[i][j] = '1';
                    }else{
                        form[i][j] = '1';
                    }
                }else{
                    if(form[i - 1][j + 1] == '1'){
                        form[i][j] = '1';
                    }else{
                        form[i][j] = '0';
                    }
                }
            }else if(j == n - 1){
                if(form[i - 1][j - 1] == '1'){
                    if(form[i - 1][j] == '1'){
                        form[i][j] = '1';
                    }else{
                        form[i][j] = '0';
                    }
                }else{
                    if(form[i - 1][j] == '1'){
                        form[i][j] = '1';
                    }else{
                        form[i][j] = '0';
                    }
                }
            }else{
                if(form[i - 1][j - 1] == '1'){
                    if(form[i - 1][j] == '1'){
                        if(form[i - 1][j + 1] == '1'){
                            form[i][j] = '0';
                        }else{
                            form[i][j] = '1';
                        }
                    }else{
                        if(form[i - 1][j + 1] == '1'){
                            form[i][j] = '1';
                        }else{
                            form[i][j] = '0';
                        }
                    }
                }else{
                    if(form[i - 1][j] == '1'){
                        if(form[i - 1][j + 1] == '1'){
                            form[i][j] = '1';
                        }else{
                            form[i][j] = '1';
                        }
                    }else{
                        if(form[i - 1][j + 1] == '1'){
                            form[i][j] = '1';
                        }else{
                            form[i][j] = '0';
                        }
                    }
                }
            }
        }
    }
    
    for(int i = 1 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%c" , form[i][j]);
        }
        printf("\n");
    }


    return 0;
}