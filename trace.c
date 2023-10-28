#include<stdio.h>
int main(){

    int n , m , x0 , y0;
    scanf("%d%d%d%d" , &n , &m , &x0 , &y0);
    getchar();
    char map[51][51];
    int Map[51][51] = {0};
    int track[3000][2] = {0};
    Map[x0 - 1][y0 - 1] = 1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            scanf("%c" , &map[i][j]);
        }
        getchar();
    }

    int ans = 1;
    int x = x0 - 1, y = y0 - 1;
    int vector[4][2] = {{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
    for(int v = 0 ; v < 3000 ; v++){
        if(x == 0){
            if(y == 0){
                for(int k = 0 ; k < 3; k += 2){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }else if(y == m - 1){
                for(int k = 0 ; k < 4; k += 3){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }else{
                for(int k = 0 ; k < 4; k++){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(newx == -1){
                        continue;
                    }
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }
        }else if(x == n - 1){
            if(y == 0){
                for(int k = 1 ; k < 3; k++){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }else if(y == m - 1){
                for(int k = 1 ; k < 4; k += 2){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }else{
                for(int k = 0 ; k < 4; k++){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(newx == 1){
                        continue;
                    }
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }
        }else{
            if(y == 0){
                for(int k = 0 ; k < 4; k++){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(newy == -1){
                        continue;
                    }
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }else if(y == m - 1){
                for(int k = 0 ; k < 4; k++){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(newy == 1){
                        continue;
                    }
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }
            }else{
                for(int k = 0 ; k < 4; k++){
                    int newx = x + vector[k][0];
                    int newy = y + vector[k][1];
                    if(map[newx][newy] == '#' && Map[newx][newy] == 0){
                        x = newx;
                        y = newy;
                        Map[newx][newy] = 1;
                        track[v][0] = newx + 1;
                        track[v][1] = newy + 1;
                        ans++;
                        break;
                    }   
                }   
            }
        }
    }

    printf("%d\n" , ans);
    printf("%d %d\n" , x0 , y0);
    for(int v = 0 ; v < ans - 1 ; v++){
        printf("%d %d\n" , track[v][0] , track[v][1]);
    }






    return 0;
}