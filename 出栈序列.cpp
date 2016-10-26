//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

typedef struct sdata
{
    int  data;
    struct sdata *pre;
} SNODE;

int m=0,n=0;
int temp=0;
int main()
{
    sdata *head=new sdata;
    head->data=0;
    head->pre=NULL;
    sdata *font=head;
    sdata *temp;
    int tem;
    int sss=0;
    while(scanf("%d%d",&n,&m),n&&m)
    {
        if(sss!=0)
            printf("\n");
        sss=1;
        while(m--)
        {
            int T=1;
            int flag=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&tem);
                if(font->data==tem)
                {
                    temp=font;
                    font=font->pre;
                    delete temp;
                }
                else
                {
                    while(T<=tem)
                    {
                        temp=new sdata;
                        temp->data=T;
                        T++;
                        temp->pre=font;
                        font=temp;
                    }
                    if(font->data==tem)
                    {
                        temp=font;
                        font=font->pre;
                        delete temp;
                    }
                    else
                    {
                        flag=1;
                    }
                }
            }
            if(flag==1)
                printf("No\n");
            else
                printf("Yes\n");
            while(font->data!=0)
            {
                temp=font;
                font=font->pre;
                delete temp;
            }
        }
    }
    return 0;
}
