//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <algorithm>

int Matrix[17];
char op;

void go_w()
{
    for(int i=5;i<17;i++)
    {
        int num=i;
        if(Matrix[num-4]==0)
        {
            while(num-4>0&&Matrix[num-4]==0){
                Matrix[num-4]=Matrix[num];
                Matrix[num]=0;
                num-=4;
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=0;j<4;j++)
        {
            int num=i+j*4;
            if(Matrix[num]==Matrix[num+4])
            {
                Matrix[num]+=Matrix[num+4];
                Matrix[num+4]=0;
                num+=4;
                for(;num<13;num+=4)
                {
                    Matrix[num]=Matrix[num+4];
                    Matrix[num+4]=0;
                }
            }
        }
    }
}

void go_a()
{
    for(int i=0;i<4;i++)
    {
        for(int j=2;j<=4;j++)
        {
            int num =j+i*4;
            if(Matrix[num-1]==0)
            {
                while((num-1)%4>=1&&Matrix[num-1]==0){
                    Matrix[num-1]=Matrix[num];
                    Matrix[num]=0;
                    num--;
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            int num=j+i*4;
            if(Matrix[num]==Matrix[num+1])
            {
                Matrix[num]+=Matrix[num+1];
                Matrix[num+1]=0;
                num+=1;
                for ( ; num%4!=0; num++)
                {
                    Matrix[num]=Matrix[num+1];
                    Matrix[num+1]=0;
                }
            }
        }
    }
}

void go_s()
{
    for(int i=12;i>0;i--)
    {
        int num=i;
        if(Matrix[num+4]==0)
        {
            while(num+4<17&&Matrix[num+4]==0){
                Matrix[num+4]=Matrix[num];
                Matrix[num]=0;
                num+=4;
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=3;j>0;j--)
        {
            int num=i+j*4;
            if(Matrix[num]==Matrix[num-4])
            {
                Matrix[num]+=Matrix[num-4];
                Matrix[num-4]=0;
                num-=4;
                for( ;num>4;num-=4)
                {
                    Matrix[num]=Matrix[num-4];
                    Matrix[num-4]=0;
                }
            }
        }
    }
}

void go_d()
{
    for(int i=0;i<4;i++)
    {
        for(int j=3;j>=1;j--)
        {
            int num =j+i*4;
            if(Matrix[num+1]==0)
            {
                while((num+1)%4!=1&&Matrix[num+1]==0){
                    Matrix[num+1]=Matrix[num];
                    Matrix[num]=0;
                    num++;
                }
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=4;j>1;j--)
        {
            int num=j+i*4;
            if(Matrix[num]==Matrix[num-1])
            {
                Matrix[num]+=Matrix[num-1];
                Matrix[num-1]=0;
                num-=1;
                for( ;num%4!=1;num--)
                {
                    Matrix[num]=Matrix[num-1];
                    Matrix[num-1]=0;
                }
            }
        }
    }
}

void operation()
{
    switch (op) {
        case 'w':
            go_w();
            break;
        case 'a':
            go_a();
            break;
        case 's':
            go_s();
            break;
        case 'd':
            go_d();
            break;
        default:
            break;
    }
    
}

int main()
{
    int a,b;
    for(int i=1;i<17;i++)
    {
        scanf("%d",&Matrix[i]);
    }
    
    getchar();
    op=getchar();
    
    while(op!='\n')
    {
        operation();
        scanf("%d%d",&a,&b);
        while(1)
        {
            if(Matrix[a]==0)
            {
                Matrix[a]=b;
                break;
            }
            else{
                a=a%16+1;
            }
        }
        op=getchar();
        if(op=='\n')
        {
            break;
        }
        else
        {
            op=getchar();
        }
    }
    for(int i=1;i<16;i++)
    {
        printf("%d ",Matrix[i]);
    }
    printf("%d\n",Matrix[16]);
}
