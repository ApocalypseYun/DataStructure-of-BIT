//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//


#include<cstdio>
#include<iostream>
#include<string.h>
#define ELEM_SIZE 200

using namespace std;

typedef struct{
    char data[ELEM_SIZE];
    int top;
}ST;

ST operationStack, numberStack;
char exr[ELEM_SIZE];
int vle[200];
char tbe[10][10] = {">><<<><>",">><<<><>",">>>><><>",">>>><><>","<<<<<=< ",">>>> >>>",">>>><><>","<<<<< <="};
char POPOPRETION(ST &STACK){
    return STACK.data[--STACK.top];
}

void push(ST &STACK, char c){
    STACK.data[STACK.top++] = c;
    return;
}

char getTop(ST STACK){
    return STACK.data[STACK.top-1];
}
int isLet(char c){
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

char comp(char optop, char op1){
    return tbe[vle[optop]][vle[op1]];
}
int main(){
    vle['+'] = 0;
    vle['-'] = 1;
    vle['*'] = 2;
    vle['/'] = 3;
    vle['('] = 4;
    vle[')'] = 5;
    vle['^'] = 6;
    vle['#'] = 7;
    int times;
    cin >> times;
    while(times--){
        int i = 1;
        memset(exr, 0, sizeof(exr));
        scanf("%s", exr+1);
        exr[0] = '#';
        operationStack.top = 0;
        numberStack.top = 0;
        push(operationStack, '#');
        while(exr[i] != '#' || getTop(operationStack) != '#'){
            if(isLet(exr[i])){
                push(numberStack, exr[i]);
                putchar(exr[i++]);
            }
            else{
                switch(comp(getTop(operationStack), exr[i])){
                    case '<':{
                        push(operationStack, exr[i++]);
                        break;
                    }
                    case '=':{
                        POPOPRETION(operationStack);
                        i++;
                        break;
                    }
                    case '>':{
                        POPOPRETION(numberStack);
                        POPOPRETION(numberStack);
                        putchar(POPOPRETION(operationStack));
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
}
