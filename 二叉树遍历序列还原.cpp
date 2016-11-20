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
const int N = 10;

char in[N], post[N];

struct Node
{
    char data;
    Node *left, *right;
    Node(): left(NULL), right(NULL) {}
    Node(char data, Node *left = NULL, Node *right = NULL):
        data(data), left(left), right(right) {}
};

int find(char s[], int begin, int end, char c)
{
    for (int i = begin; i < end; i++)
        if (s[i] == c) return i;
    return end;
}

Node *build(int in_begin, int in_end, int post_begin, int post_end);
queue<Node *> q;
void bfs(Node *T)
{
    while (!q.empty()) q.pop();
    q.push(T);
    while (!q.empty())
    {
        Node *p = q.front(); q.pop();
        printf("%c", p->data);
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);        
    }
    printf("\n");
}

int main()
{
    scanf("%s%s", in, post);
    Node *T = build(0, strlen(in), 0, strlen(post));
    bfs(T);
    return 0;
}

Node *build(int in_begin, int in_end, int post_begin, int post_end)
{
    if (in_begin == in_end) return NULL;
    int root = find(in, in_begin, in_end, post[post_end - 1]);
    Node *p = new Node(post[post_end - 1]);
    p->left = build(in_begin, root, post_begin, post_begin + root - in_begin);
    p->right = build(root + 1, in_end, post_begin + root - in_begin, post_end - 1);
    return p;
}
