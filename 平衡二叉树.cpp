//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Node
{
    char data;
    int bf;
    Node *left, *right;
    Node() {}
    Node (int data, int bf, Node *left, Node *right):
        data(data), bf(bf), left(left), right(right) {}
} *T;

void init()
{
    T = NULL;
}

void left_rotate(Node *&T)
{
    Node *rc = T->right;
    T->right = rc->left;
    rc->left = T;
    T = rc;
}

void right_rotate(Node *&T)
{
    Node *lc = T->left;
    T->left = lc->right;
    lc->right = T;
    T = lc;
}

void left_balance(Node *&T)
{
    if (T->left->bf == 1)
    {
        T->bf = T->left->bf = 0;
        right_rotate(T);
    }
    else
    {
        switch (T->left->right->bf)
        {
            case 1: T->bf = -1; T->left->bf = 0; break;
            case 0: T->bf = T->left->bf = 0; break;
            case -1: T->bf = 0; T->left->bf = 1; break;
        }
        T->left->right->bf = 0;
        left_rotate(T->left);
        right_rotate(T);
    }
}

void right_balance(Node *&T);

bool insert(Node *&T, char c)
{
    if (T == NULL)
    {
        T = new Node(c, 0, NULL, NULL);
        return true;
    }
    if (c == T->data) return false;
    if (c < T->data)
    {
        if (insert(T->left, c))
        {
            switch (T->bf)
            {
                case -1: T->bf = 0; return false;
                case 0: T->bf = 1; return true;
                case 1: left_balance(T); return false;
            }
        }
    }
    else
    {
        if (insert(T->right, c))
        {
            switch (T->bf)
            {
                case 1: T->bf = 0; return false;
                case 0: T->bf = -1; return true;
                case -1: right_balance(T); return false;
            }
        }
    }
}

void pre_order(Node *T)
{
    if (T == NULL) return;
    printf("%c", T->data);
    pre_order(T->left);
    pre_order(T->right);
}

void in_order(Node *T)
{
    if (T == NULL) return;
    in_order(T->left);
    printf("%c", T->data);
    in_order(T->right);
}

void post_order(Node *T)
{
    if (T == NULL) return;
    post_order(T->left);
    post_order(T->right);
    printf("%c", T->data);
}

void indent(Node *T, int deep)
{
    if (T == NULL) return;
    indent(T->right, deep + 1);
    for (int i = 1; i <= deep; i++) printf("    ");
    printf("%c\n", T->data);
    indent(T->left, deep + 1);
}

int main()
{
    init();
    char c;
    while ((c = getchar()) != '\n') insert(T, c);

    printf("Preorder: ");
    pre_order(T);
    printf("\n");

    printf("Inorder: ");
    in_order(T);
    printf("\n");

    printf("Postorder: ");
    post_order(T);
    printf("\n");

    printf("Tree:\n");
    indent(T, 0);
    return 0;
}

void right_balance(Node *&T)
{
    if (T->right->bf == -1)
    {
        T->bf = T->right->bf = 0;
        left_rotate(T);
    }
    else
    {
        switch (T->right->left->bf)
        {
            case -1: T->bf = 1; T->right->bf = 0; break;
            case 0: T->bf = T->right->bf = 0; break;
            case 1: T->bf = 0; T->right->bf = -1; break;
        }
        T->right->left->bf = 0;
        right_rotate(T->right);
        left_rotate(T);
    }
}
