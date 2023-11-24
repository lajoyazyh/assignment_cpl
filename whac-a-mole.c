#include<stdio.h>

int map[1000][1000] = {0};
int maxValue = 0;
int value = 0;
int ansN = 1;
int ans[50][2] = {0};
int d;
int direction = 1;
int temp1 = 0;
int temp2 = 0;

void search(int x , int y , int map[1000][1000] , int n , int m){
    temp1 = 0;
    temp2 = 0;
    
    if(x < 1 || x > n){
        return;
    }
    if(y < 1 || y > m){
        y = 1;
        goto stupid;
    }

    if(x == 1 && y == 1){
        for(int i = 0 ; i <= d ; i++){
            for(int j = 0 ; j <= d - i ; j++){
                maxValue += map[d + i][d + j];
            }
        }
        value = maxValue;
        ans[0][0] = 1;
        ans[0][1] = 1;
    }else{
        for(int i = 0 ; i <= d ; i++){
            if(direction == 1){
                temp1 += map[x - (d - i) + d - 1][y + i + d - 1];
                temp1 += map[x + (d - i) + d - 1][y + i + d - 1];
            }else{
                temp1 += map[x - (d - i) + d - 1][y - i + d - 1];
                temp1 += map[x + (d - i) + d - 1][y - i + d - 1];
            }
        
            if(direction == 1){
                temp2 += map[x - (d - i) + d - 1][y - 1 - i + d - 1];
                temp2 += map[x + (d - i) + d - 1][y - 1 - i + d - 1];
            }else{
                temp2 += map[x - (d - i) + d - 1][y + 1 + i + d - 1];
                temp2 += map[x + (d - i) + d - 1][y + 1 + i + d - 1];
            }
        
        }
        if(direction == 1){
            temp1 -= map[x + d - 1][y + d + d - 1];
            temp2 -= map[x + d - 1][y - 1 - d + d - 1];
        }else{
            temp1 -= map[x + d - 1][y - d + d - 1];
            temp2 -= map[x + d - 1][y + 1 + d + d - 1];   
        }
        value += (temp1 - temp2);

        if(value > maxValue){
            maxValue = value;
            ansN = 1;
            ans[0][0] = x;
            ans[0][1] = y;
        }else if(value == maxValue){
            ansN++;
            ans[ansN - 1][0] = x;
            ans[ansN - 1][1] = y;
        }
    }
stupid:
    if(direction == 1){
        if(y + 1 <= m){
            search(x , y + 1 , map  , n , m);
        }else{
            if(x + 1 > n){
                return;
            }
            temp1 = 0;
            temp2 = 0;
            x += 1;
            for(int i = 0 ; i <= d ; i++){
                temp1 += map[x + (d - i) + d - 1][y + i + d - 1];
                temp1 += map[x + (d - i) + d - 1][y - i + d - 1];
                temp2 += map[x - 1 - (d - i) + d - 1][y + i + d - 1];
                temp2 += map[x - 1 - (d - i) + d - 1][y - i + d - 1];
            }
            temp1 -= map[x + d + d - 1][y + d - 1];
            temp2 -= map[x  - 1 - d + d - 1][y + d - 1];
            value += (temp1 - temp2);

            if(value > maxValue){
                maxValue = value;
                ansN = 1;
                ans[0][0] = x;
                ans[0][1] = y;
            }else if(value == maxValue){
                ansN++;
                ans[ansN - 1][0] = x;
                ans[ansN - 1][1] = y;
            }
            direction = 2;
            search(x , y - 1 , map , n , m);
            
        }

    }else{
        if(y - 1 >= 1){
            search(x , y - 1 , map , n , m);
        }else{
            if(x + 1 > n){
                return;
            }
            temp1 = 0;
            temp2 = 0;
            x += 1;
            for(int i = 0 ; i <= d ; i++){
                temp1 += map[x + (d - i) + d - 1][y + i + d - 1];
                temp1 += map[x + (d - i) + d - 1][y - i + d - 1];
                temp2 += map[x - 1 - (d - i) + d - 1][y + i + d - 1];
                temp2 += map[x - 1 - (d - i) + d - 1][y - i + d - 1];
            }
            temp1 -= map[x + d + d - 1][y + d - 1];
            temp2 -= map[x - 1 - d + d - 1][y + d - 1];
            value += (temp1 - temp2);

            if(value > maxValue){
                maxValue = value;
                ansN = 1;
                ans[0][0] = x;
                ans[0][1] = y;
            }else if(value == maxValue){
                ansN++;
                ans[ansN - 1][0] = x;
                ans[ansN - 1][1] = y;
            }
            direction = 1;
            search(x , y + 1 , map , n , m);            
        }
    }
return;
}

int main(){
    int n , m;
    scanf("%d%d%d" , &n , &m , &d);
    for(int i = d ; i < d + n ; i++){
        for(int j = d ; j < d + m ; j++){
            scanf("%d" , &map[i][j]);
        }
    } 
    
    
    
    search(1 , 1 , map , n , m);
    printf("%d %d" , maxValue , ansN);
    
        for(int i = 0 ; i < ansN ; i++){
            printf("\n%d %d" , ans[i][0] , ans[i][1]);
        }        
    

    return 0;
}