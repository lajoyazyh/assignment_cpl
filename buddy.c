#include<stdio.h>
#include<string.h>
#include<math.h>
int storage[10000] = {0};
int occupy[10000] = {0};
int num = 1;


void A(int k , int id){
    for(int i = 1 ; i <= num ; i++){
        if(occupy[i] == 0 && storage[i] == k){
            occupy[i] = id;
            return;
        }else if(occupy[i] == 0 && storage[i] > k){
            storage[i]--;
            for(int j = num ; j >= i ; j--){
                storage[j + 1] = storage[j];
                occupy[j + 1] = occupy[j];
            }
            num++;
            A(k , id);
            return;
        }
    }
}

void Q(){
    printf("%d\n" , num);
    for(int i = 1 ; i <= num ; i++){
        printf("%d " , occupy[i]);
    }
    printf("\n");
}

int main(){
    int max = 0;
    scanf("%d" , &max);
    getchar();
    storage[1] = max;
    int q = 0; 
    scanf("%d" , &q);
    getchar();
    for(int i = 1 ; i <= q ; i++){
        char operation;
        scanf(" %c", &operation);
        getchar();
      

        if(operation == 'Q'){
            Q();
        }else if(operation == 'A'){
            int require = 0;
            int id = 0;
            int given = 0;
            scanf("%d" , &id);
            getchar();
            scanf("%d" , &require);
            getchar();
            for(int t = 0 ; t <= max ; t++){
                if(pow(2 , t) >= require){
                    given = t;
                    break;
                }
            }
            A(given , id);
        }
    }
    return 0;
}