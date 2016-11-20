//
//  main.cpp
//  数据结构
//
//  Created by 刘冠中 on 2016/10/18.
//  Copyright © 2016年 刘冠中. All rights reserved.
//
//
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

char s[N];
int degree[N], tree_degree;

void indent(char s[]);

void count_degree(char *&p)
{
    int ans = 0, left = 0;
    while (*p != '\0')
    {
        if (isalpha(*p))
        {
            count_degree(++p);
            left--;
        }
        else if (*p == '(')
        {
            ans++;
            left++;
        }
        else if (*p == ')')
        {
            left--;
            if (left == -1)
            {
                degree[ans]++;
                tree_degree = max(tree_degree, ans);
                return;
            }
        }
        p++;
    }
}

int main()
{
    scanf("%s", s);

    if (s[1] == ')')
    {
        printf("Degree of tree: 0\n");
        printf("Number of nodes of degree 0: 0\n");
        return 0;
    }

    indent(s);

    memset(degree, 0, sizeof(degree));
    tree_degree = 0;
    char *p = s + 1;
    count_degree(p);

    printf("Degree of tree: %d\n", tree_degree);
    for (int i = 0; i <= tree_degree; i++) 
        printf("Number of nodes of degree %d: %d\n", i, degree[i]);
    return 0;
}

void indent(char s[])
{
    int len = strlen(s);
    int t = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            t++;
        }
        else if (s[i] == ')')
        {
            t--;
        }
        else if (isalpha(s[i]))
        {
            for (int k = 1; k < t; k++) printf("    ");
            printf("%c\n", s[i]);

        }
    }
}
