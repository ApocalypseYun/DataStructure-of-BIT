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
#include <queue>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Node
{
    char data;
    Node *left, *right;
    Node(): left(NULL), right(NULL) {}
    Node(char data, Node *left = NULL, Node *right = NULL): 
        data(data), left(left), right(right) {}
};

Node *build(char s[])
{
    if (strlen(s) == 0 || s[0] == '#') return NULL;
    Node *T = new Node(s[0]);
    queue<Node *> que;
    que.push(T);
    int len = strlen(s);
    int i = 1;
    while (i < len && !que.empty())
    {
        Node *p = que.front(); que.pop();
        if (p == NULL) continue;
        if (s[i] != '#')
        {
            p->left = new Node(s[i]);
            que.push(p->left);
        }
        i++;
        if (i < len && s[i] != '#')
        {
            p->right = new Node(s[i]);
            que.push(p->right);
        }
        i++;
    }
    return T;
}

void indent(Node *T, int deep);
void pre_order(Node *T);
void in_order(Node *T);
void post_order(Node *T);
int count_leaf(Node *T);
void swap_node(Node *T);

char s[N];

int main()
{
    scanf("%s", s);

    int len = strlen(s);
    if (s[len - 1] != '#' && s[len - 2] != '#' 
        && s[len - 3] == '#' && s[len - 4] == '#' 
        && s[len - 5] == '#'  && s[len - 6] == '#' 
        && s[len - 7] == '#' && s[len - 8] == '#')
    {
        s[len - 6] = s[len - 2];
        s[len - 5] = s[len - 1];
        s[len - 4] = '\0';
    }

    Node *T = build(s);

    printf("BiTree\n");
    indent(T, 0);

    printf("pre_sequence  : ");
    pre_order(T);
    printf("\n");

    printf("in_sequence   : ");
    in_order(T);
    printf("\n");

    printf("post_sequence : ");
    post_order(T);
    printf("\n");

    printf("Number of leaf: %d\n", count_leaf(T));

    swap_node(T);
    printf("BiTree swapped\n");
    indent(T, 0);

    printf("pre_sequence  : ");
    pre_order(T);
    printf("\n");

    printf("in_sequence   : ");
    in_order(T);
    printf("\n");

    printf("post_sequence : ");
    post_order(T);
    printf("\n");
    return 0;
}


void indent(Node *T, int deep)
{
    if (T == NULL) return;
    for (int i = 1; i <= deep; i++) printf("    ");
    printf("%c\n", T->data);
    indent(T->left, deep + 1);
    indent(T->right, deep + 1);
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

int count_leaf(Node *T)
{
    if (T == NULL) return 0;
    if (T->left == NULL && T->right == NULL) return 1;
    return count_leaf(T->left) + count_leaf(T->right);
}

void swap_node(Node *T)
{
    if (T == NULL) return;
    swap(T->left, T->right);
    swap_node(T->left);
    swap_node(T->right);
}
