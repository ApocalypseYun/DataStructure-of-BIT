//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//


#include<stdio.h>
#include<string.h>
#include<math.h>
#define CORRECT 0
#define DIVZERO 1
#define ERROR 2

typedef struct{
    
    int data[200];
    int top;
} NODE;

NODE numberStack, operationStack;
char lr = 0;
char exr[500], vle[200];
char table[10][10] = {">><<<><<>",">><<<><<>",">>>><>>>>",">>>><>>>>","<<<<<=<< ",">>>> >>>>",">>>><>>>>",">>>><>><>","<<<<< <<="};
int CF = CORRECT;

int pop(NODE &p){
    
    if(p.top == 0){
        
        CF = ERROR;
        return 0;
    }
    return p.data[--p.top];
}

void push(NODE &p, int e){
    
    p.data[p.top++] = e;
    return;
}

int getTop(NODE p){
    return p.data[p.top-1];
}
int transfer(int &i){
    int num = 0;
    while(exr[i]>='0' && exr[i]<='9')
    {
        num *= 10;
        num += exr[i]-'0';
        i++;
    }
    return num;
}

void init(){
    CF = 0;
    lr = '0';
    memset(exr, 0, sizeof(exr));
    scanf("%s", exr+1);
    exr[0] = '#';
    exr[strlen(exr)] = '#';
    numberStack.top = 0;
    operationStack.top = 0;
    push(operationStack, '#');
    return;
}

int isNum(char c)
{
    return (c>='0' && c<='9');
}

int comp(char optop, char op1)
{
    return table[vle[optop]][vle[op1]];
}

int operate(int num1, char op, int num2)
{
    int result = 0;
    switch(op)
    {
        case '+':{
            result = num1+num2;
            break;
        }
        case '-':{
            result = num1-num2;
            break;
        }
        case '*':{
            result = num1*num2;
            break;
        }
        case '/':{
            if(num2 == 0)
            {
                CF = DIVZERO;
                return 0;
            }
            result = num1/num2;
            break;
        }
        case '%':{
            result = num1 % num2;
            break;
        }
        case '^':{
            if(num2 < 0)
            {
                CF = ERROR;
                return 0;
            }
            result = pow(num1, num2);
            break;
        }
        default :{
            CF = ERROR;
            break;
        }
    }
    return result;
}

int main(){
    int times;
    scanf("%d", &times);
    vle['+'] = 0;
    vle['-'] = 1;
    vle['*'] = 2;
    vle['/'] = 3;
    vle['('] = 4;
    vle[')'] = 5;
    vle['%'] = 6;
    vle['^'] = 7;
    vle['#'] = 8;
    while(times--){
        int i = 1;
        init();
        while(exr[i]!='#' || getTop(operationStack)!='#'){
            if(isNum(exr[i])){
                int num = transfer(i);
                push(numberStack, num);
                lr = 0;
            }
            else{
                if(exr[i] == '-' && !isNum(exr[i-1]) && exr[i-1]!=')'){
                    i++;
                    int num = 0-transfer(i);
                    push(numberStack, num);
                    lr = 0;
                    continue;
                }
                if(exr[i]!='(' && lr != ')' && lr != 0){
                    CF = ERROR;
                    break;
                }
                lr = exr[i];
                switch(comp(getTop(operationStack), exr[i])){
                    case '<':{
                        push(operationStack, exr[i]);
                        i++;
                        break;
                    }
                    case '=':{
                        pop(operationStack);
                        i++;
                        break;
                    }
                    case '>':{
                        int number1, number2, result;
                        number2 = pop(numberStack);
                        number1 = pop(numberStack);
                        if(CF)break;
                        char op = pop(operationStack);
                        result = operate(number1, op, number2);
                        if(CF)break;
                        push(numberStack, result);
                        lr = 0;
                        break;
                    }
                    case ' ':{
                        CF = ERROR;
                        break;
                    }
                }
            }
            if(CF)
                break;
        }
        if(!CF&&(operationStack.top!=1 || numberStack.top!=1))CF = ERROR;
        if(CF)
        {
            switch(CF)
            {
                case ERROR:{
                    printf("error.\n");
                    break;
                }
                case DIVZERO:{
                    printf("Divide 0.\n");
                    break;
                }
            }
        }
        else printf("%d\n", pop(numberStack));
    }
}
