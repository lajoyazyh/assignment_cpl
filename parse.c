#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char rule[1000] = {0};
char instruction[10005] = {0};
char ans[10005] = {0};
int main(){
    scanf("%s" , rule);
    getchar();
    fgets(instruction , 10005 , stdin);
    int p = 0;
    ///读取程序名
    while(* (instruction + p) != ' ' && * (instruction + p) != '\n'){
        * (ans + (p)) = * (instruction + (p));
        p++;
    }
    * (ans + p) = '\n';

    int ansp = p; ///记录答案数组中的当前位置
    int len = strlen(rule);
    while(* (instruction + p) != '\n'){
        if(*(instruction + p) != '-'){///找第一个‘-’
            p++;
        }else{
            p++;
            ///传入-后的参数
            char temp = * (instruction + p);
            int tempflag = 0;
            ///判断是否在rule中
            for(int i = 0 ; i < len ; i++){
                if(* (rule + i) == temp){///判断在rule中
                    tempflag = 1;
                    ansp++;
                    * (ans + (ansp ++)) = temp;
                    * (ans + (ansp ++)) = '\n';
                    p++;
                    if(* (rule + i + 1) == ':'){///如果需要后缀参数
                        ansp--;
                        * (ans + (ansp ++)) = '=';
                        int tempflag2 = 0;
                        p++;
                        while( * (instruction + p) != '\n' && * (instruction + p) != ' ' && * (instruction + p) != '\0'){    
                            * (ans + (ansp ++)) = * (instruction + (p++));
                            tempflag2 = 1;   
                        }
                        * (ans + (ansp ++)) = '\n';
                        if(tempflag2 == 0){///若出现缺少值的参数
                            int tempa = 0;
                            while(* (ans + (tempa++)) != '\n'){
                                printf("%c" , *(ans + tempa - 1));
                            }
                            printf(": option requires an argument -- '%c'" , temp);
                            return 0;
                        }
                    }
                    ansp--;
                    break;
                }
            }
            ///若出现规划中未出现的参数
            if(tempflag == 0){
                int tempa = 0;
                while(* (ans + (tempa++)) != '\n'){
                    printf("%c" , *(ans + tempa - 1));
                }
                printf(": invalid option -- '%c'" , temp);
                return 0;
            } 
            
        }
    }
    for(int i = 0 ; i <= ansp ; i++){
        printf("%c" , * (ans + i));
    }
    

    return 0;

}
