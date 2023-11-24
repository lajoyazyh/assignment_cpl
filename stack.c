#include<stdio.h>
#include<string.h>
char stack[10004] = {0};
int topnum = 0;

void push(char m){
    topnum++;
    stack[topnum] = m;
}

void pop(){
    if(topnum == 0){
        printf("Empty\n");
    }else{
        topnum--;
    }
}

void top(){
    if(topnum == 0){
        printf("Empty\n");
    }else{
        printf("%c\n" , stack[topnum]);
    }

}

void print(){
    if(topnum == 0){
        printf("Empty\n");
    }else{
        int i = topnum;
        while(i >= 1){
            printf("| %c |\n" , stack[i--]);
        }
        printf("|===|\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);

        if (strcmp(operation, "push") == 0) {
            char item;
            scanf(" %c", &item);
            push(item);
        } else if (strcmp(operation, "pop") == 0) {
            pop();
        } else if (strcmp(operation, "top") == 0) {
            top();
        } else if (strcmp(operation, "print") == 0) {
            print();
        }
    }

    return 0;
}