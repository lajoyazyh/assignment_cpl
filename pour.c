#include<stdio.h>
int Va , Vb , Vc;
int a0 , b0 , c0;
int ans = 0;

void try(int a , int b , int c , int k){
    int a1 = a , b1 = b , c1 = c;
    if(k < 0){
        return;
    }
    if(a == a0 && b == b0 && c ==c0){
        ans = 1;
        return;
    }
    //结束条件↑
    if(b1 != 0){
        if(a1 + b1 > Va){
            try(Va , 0 , c , k - 1);
        }else{
            try(a1 + b1 , 0 , c , k - 1);
        }    
    }
    if(c1 != 0){
        if(a1 + c1 > Va){
            try(Va , b , 0 , k - 1);
        }else{
            try(a1 + c1 , b , 0 , k - 1);
        } 
    }
    //倒入杯1↑
    if(a1 != 0){
        if(a1 + b1 > Vb){
            try(0 , Vb , c , k - 1);
        }else{
            try(0 , a1 + b1 , c , k - 1);
        }
    }
    if(c1 != 0){
        if(c1 + b1 > Vb){
            try(a , Vb , 0 , k - 1);
        }else{
            try(a , c1 + b1 , 0 , k - 1);
        }   
    }
    //倒入杯2↑
    if(b1 != 0){
        if(b1 + c1 > Vc){
            try(a1 , 0 , Vc , k - 1);
        }else{
            try(a1 , 0 , b1 + c1 , k - 1);
        }   
    }
    if(a1 != 0){
        if(a1 + c1 > Vc){
            try(0 , b , Vc , k - 1);
        }else{
            try(0 , b , a1 + c1 , k - 1);
        }   
    }
    //倒入杯3↑
    
    if(ans != 1){
        ans = 0;
    }

    return;
}

int main(){
    int k , a , b , c;
    scanf("%d%d%d%d%d%d%d%d%d%d" , &k , &Va , &Vb , &Vc , &a , &b , &c , &a0 , &b0 , &c0);
    try(a , b , c , k);
    if(ans == 1){
        printf("Yes");
    }else{
        printf("No");
    }


    return 0;
}

