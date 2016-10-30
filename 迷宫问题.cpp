//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//
#include <stdio.h>

typedef struct
{
    char x, y;
}STACK;

STACK POS[200];
int toption = 0;

char maap[102][102] = {0};

void PUSHOPERATION(char a, char b)
{
    POS[toption].x = a;
    POS[toption++].y = b;
    maap[a][b] = 2;
}

int main(){
    int m, n, i, j;
    scanf("%d%d",&m, &n);
    for (i=0; i<=m+1; i++)
        for (j=0; j<=n+1; j++)
            if (i*j>0 && i<=m && j<=n)
                scanf("%c",&maap[i][j]);
            else
                maap[i][j] = 2;
    if (maap[1][1] == 1){
        printf("There is no solution!\n");
        return 0;
    }
    PUSHOPERATION(1,1);
    while (1){
        if (toption == 0){
            printf("There is no solution!\n");
            return 0;
        }
        i = POS[toption-1].x;
        j = POS[toption-1].y;
        if (i==m && j==n){
            break;
        }
        if(maap[i+1][j] == 0){
            PUSHOPERATION(i+1, j);
            continue;
        }
        else if (maap[i][j+1] == 0){
            PUSHOPERATION(i, j+1);
            continue;
        }
        else if (maap[i-1][j] == 0){
            PUSHOPERATION(i-1, j);
            continue;
        }
        else if (maap[i][j-1] == 0){
            PUSHOPERATION(i, j-1);
            continue;
        }
        toption --;
    }
    for (i=0; i<toption; i++){
        printf("<%d,%d> ",POS[i].x, POS[i].y);
    }
    printf("\n");
    return 0;
}
