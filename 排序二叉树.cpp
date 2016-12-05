//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//
#include <cstdio>
#include <cstring>

struct tree{
    int x;
    struct tree *left,*right;
};

void add(int num ,struct tree *root)
{
    struct tree *p=root;
    struct tree *q=new struct tree;
    q->x=num;
    while(1)
    {
        if(num<p->x)
        {
            if(p->left==NULL)
            {
                p->left=q;
                return;
            }
            else
                p=p->left;
        }
        else{
            if(p->right==NULL)
            {
                p->right=q;
                return;
            }
            else
                p=p->right;
        }
    }
}

void indent(struct tree *T, int deep)
{
    if (!T) return;
    indent(T->left, deep + 1);
    for (int i = 1; i <= deep; i++) printf("    ");
    printf("%d\n", T->x);
    indent(T->right, deep + 1);
}

void in_order(struct tree *root)
{
    if(root==NULL) return;
    in_order(root->left);
    printf(" %d",root->x);
    in_order(root->right);
}
int main()
{
    struct tree *root=new struct tree;
    int num=0;
    scanf("%d",&num);
    root->x=num;
    scanf("%d",&num);
    while(num!=0)
    {
        add(num,root);
        scanf("%d",&num);
    }
    indent(root, 0);
    printf("\n");
    in_order(root);
    printf("\n");
}
