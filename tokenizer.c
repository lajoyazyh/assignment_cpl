#include<stdio.h>
#include<string.h>

int ansp = 0;
char ans[10005][10005] = {0};
const char reserved[16][10] = { "const", "int", 
"float", "double", "long",
 "static", "void", "char",
  "extern", "return", "break", "enum",
   "struct","typedef", "union", "goto" }; 

const char integer[10][2] = {"0","1","2","3","4","5","6","7","8","9"};

const char operator[11][5] = {"+","-","*","/","=","==","!=",
">","<",">=","<="};
int turn = 0;
int process(char * input , int len){
    for(int i = 0 ; i < 16 ; i++){//////判断是不是保留值
            if(strcmp(input , reserved[i]) == 0){
                strcat(ans[turn] , "reserved ");
                turn++;
                return 1;
            }
    }
    for(int i = 0 ; i < 11 ; i++){//////判断是不是运算符
        if(strcmp(input, operator[i]) == 0){
            strcat(ans[turn] , "operator ");
            turn++;
            return 1;
        }
    }

    if((* (input) >= 'a' && * (input) <= 'z') || (* (input) >= 'A' && * (input) <= 'Z') || * (input) == '_'){/////只能为变量名
        for(int temp = 1 ; temp < len ; temp ++){
            if((*(input + temp) >= 'a' && *(input + temp) <= 'z') || 
            (*(input + temp) >= 'A' && *(input + temp) <= 'Z') || 
            (*(input + temp) >= '0' && *(input + temp) <= '9') || *(input + temp) == '_');
            else{//////////出现了命名规则以外的字符
                printf("Compile Error");
                return 0;
            }
                
        }
        strcat(ans[turn] , "variable ");
        turn++;
        return 1;
    }
    if(* input >= '0' && * input <= '9' || *input == '.'){/////数字或浮点数
        int count = 0;/////记录“ . ”出现的个数
        for(int temp = 0 ; temp < len ; temp++){
            if((* (input + temp) >= '0' && *(input +temp) <= '9'));
            else if(* (input + temp) == '.'){
                if(count == 0) count = 1;
                else{
                    printf("Compile Error");
                    return 0;
                }
            }else{
                printf("Compile Error");
                return 0;  
            }
        }
        if(count == 0){
            strcat(ans[turn] , "integer ");
            turn++;
            return 1;
        }
        else{
           strcat(ans[turn] , "float "); 
           turn++;
           return 1;
        }     
    }
    printf("Compile Error");
    return 0;  
}

int preprocess(char * input , int len){
        char *address = strchr(input, ';');   // if there's no ';' in s, it returns NULL.
        if (address == NULL){
            if(process(input , len) == 0) return 0;
            turn++;
        } 
        else {
            int position = address - input;
            if(position == 0){
                ans[turn][0] = '\n';
                turn++;
                if(*(input + 1) != '\0'){
                    return preprocess(input + 1 , len - 1);  
                }else{
                    return 1;
                }               
            }
            *(input + position) = '\0';
            if(process(input , position - 1) == 0) return 0;
            ans[turn][0] = '\n';
            turn++;
            if(*(input + position + 1) != '\0'){
                return preprocess(input + position + 1 , len - (position + 1));
            } 
        }
        return 1;
}
int main(){
    
    char Input[4098] = {0};
    char *input = Input;

    while (scanf("%s", input) != EOF) {
        if(*input == '\n') input = input + 1;
        int len = strlen(input);
        if(preprocess(input , len) == 0){
            return 0;
        }
    }
    
    for(int i = 0 ; i <= turn ; i++){
        printf("%s" , ans[i]);
    }

    return 0;
}