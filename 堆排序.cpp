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
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

int heap[N], size;

inline int L(int i)
{
    return i << 1;
}
inline int R(int i)
{
    return (i << 1) + 1;
}
inline int P(int i)
{
    return i >> 1;
}

void init();
void up(int i);
void push(int x);
int top();
void down(int i);
void pop();
void pre_order(int i);

int main()
{
    init();
    scanf("%d", &size);
    for (int i = 1; i <= size; i++) scanf("%d", &heap[i]);
    for (int i = size / 2; i >= 1; i--) down(i);
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]); printf("\n");
    pop();
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]); printf("\n");
    pop();
    for (int i = 1; i <= size; i++) printf("%d ", heap[i]); printf("\n");
    return 0;
}

void init()
{
    size = 0;
}

void up(int i)
{
    if (i == 1)
        return;
    if (heap[i] > heap[P(i)])
    {
        swap(heap[i], heap[P(i)]);
        up(P(i));
    }
}
void push(int x)
{
    heap[++size] = x;
    up(size);
}

int top()
{
    return heap[1];
}

void down(int i)
{
    int mini = i;
    if (L(i) <= size && heap[L(i)] > heap[mini])
        mini = L(i);
    if (R(i) <= size && heap[R(i)] > heap[mini])
        mini = R(i);
    if (mini != i)
    {
        swap(heap[i], heap[mini]);
        down(mini);
    }
}
void pop()
{
    heap[1] = heap[size--];
    down(1);
}

void pre_order(int i)
{
    if (i > size) return;
    printf("%d ", heap[i]);
    pre_order(L(i));
    pre_order(R(i));
}
