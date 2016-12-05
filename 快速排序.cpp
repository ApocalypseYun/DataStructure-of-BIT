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

int n, a[N], b[N];
int tmp[N], num;

int median3(int a[], int i, int j, int k)
{
    int mininum = i;
    if (a[j] < a[mininum])
        mininum = j;
    if (a[k] < a[mininum])
        mininum = k;
    if (mininum != i)
        swap(a[i], a[mininum]);
    if (a[j] > a[k])
        swap(a[j], a[k]);
    return a[j];
}

void quickSort(int a[], int left, int right);

int main()
{
    n = 0;
    memset(a, 0x7f, sizeof(a));
    while (scanf("%d", &a[n]), a[n] != INF) n++;
    num = 0;
    quickSort(a, 0, n - 1);
    printf("After Sorting:\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
    printf("Median3 Value:\n");
    if (num == 0)
    {
        printf("none\n");
    }
    else
    {
        for (int i = 0; i < num; i++) printf("%d ", tmp[i]);
        printf("\n");
    }
    return 0;
}

void quickSort(int a[], int left, int right)
{
    if (right - left + 1 <= 5)
    {
        sort(a + left, a + right + 1);
        return;
    }
    int mid = (left + right) / 2;
    int key = median3(a, left, mid, right);
    tmp[num++] = key;
    swap(a[mid], a[right - 1]);
    int i = left + 1, j = right - 2;
    while (i < j)
    {
        while (i < j && a[i] < key) i++;
        while (i < j && a[j] > key) j--;
        swap(a[i], a[j]);
        if (a[i] == key)
            i++;
        if (a[j] == key)
            j--;
    }
    swap(a[i], a[right - 1]);
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}
