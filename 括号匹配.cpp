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
#include <stack>
#include <map>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;


int main()
{
    char s[N];
    scanf("%s", s);
    int flag=0;
    int len = strlen(s);
    stack<char> sta;
    map<char, char> match;
    match[')'] = '(';
    match[']'] = '[';
    match['}'] = '{';
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            sta.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (sta.empty() || sta.top() != match[s[i]]) goto go;
            else sta.pop();
        }
    }
    flag=1;
go: if (flag) printf("Match succeed!\n");
    else printf("Match false!\n");
    return 0;
}
