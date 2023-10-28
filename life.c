#include<stdio.h>
#include<string.h>

int main(){
    int n;
    scanf("%d" , &n);
    getchar();

    char cell[1200] = {0};
    char cell_2[1200] = {0};

    cell[0] = cell[1] = cell[2] = '.';
    cell_2[0] = cell_2[1] = cell_2[2] = '.';
    int initial = 3;
    char ch;
    while((ch = getchar()) != '\n'){
        cell[initial++] = ch;
    }
    cell[initial] = '\0';
    int len = strlen(cell) - 3;

    for(int s = 1 ; s <= n ; s++){
        for(int i = 3 ; i < len + 3 ; i++){
            if(cell[i] == '.'){

                int count1 = 0;
                int count2 = 0;
                for(int j = i - 3 ; j <= i + 3 ; j++){
                    if(cell[j] == 'A'){
                        count1++;
                    }else if(cell[j] == 'B'){
                        count1 = 0;
                        break;
                    }
                }
                for(int j = i - 3 ; j <= i + 3 ; j++){
                    if(cell[j] == 'B'){
                        count2++;
                    }else if(cell[j] == 'A'){
                        count2 = 0;
                        break;
                    }
                }

                if(count1 >= 2 && count1 <= 4){
                    cell_2[i] = 'A';
                }else if(count2 >= 2 && count2 <= 4){
                    cell_2[i] = 'B';
                }else{
                    cell_2[i] = '.';
                }
            }
            /////////////////////////////////////////////////////
            else if(cell[i] == 'A'){
                int count1 = 0;
                for(int j = i - 3 ; j <= i + 3 ; j++){
                    if(cell[j] == 'A' && j != i){
                        count1++;
                    }else if(cell[j] == 'B' && j != i){
                        count1 = 0;
                        break;
                    }
                }
                if(count1 >= 5 || count1 <= 1){
                    cell_2[i] = '.';
                }else{
                    cell_2[i] = 'A';
                }
            }
            /////////////////////////////////////////////////////
            else{
                int count2 = 0;
                for(int j = i - 3 ; j <= i + 3 ; j++){
                    if(cell[j] == 'B' && j != i){
                        count2++;
                    }else if(cell[j] == 'A' && j != i){
                        count2 = 0;
                        break;
                    }
                }
                if(count2 >= 5 || count2 <= 1){
                    cell_2[i] = '.';
                }else{
                    cell_2[i] = 'B';
                }
            }
        }

        for(int i = 3 ; i < 3 + len ; i++){
            cell[i] = cell_2[i];
        }

         

    }    
    
    for(int i = 3 ; i < len + 3 ; i++){
        printf("%c" , cell[i]);
    }





    return 0;
}