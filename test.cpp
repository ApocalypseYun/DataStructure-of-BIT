#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define INF 0x3f3f3f3f;


struct Point{
    double x,y;
    int id;
}x[100001],y[100001],z[100001];

bool cmpx(Point p1, Point p2)
{
    return p1.x < p2.x;
}

bool cmpy(Point p1, Point p2)
{
    return p1.y < p2.y;
}

double distance(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void Merge(Point x[], Point y[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (x[i].y < x[j].y)
            y[k++] = x[i++];
        else
            y[k++] = x[j++];
    }
    while (i <= m)
        y[k++] = x[i++];
    while (j <= r)
        y[k++] = x[j++];
}

double closest(Point x[], Point y[], Point z[], int l, int r)
{
    if (r - l == 1)
        return distance(x[l], x[r]);
    if (r - l == 2)
    {
        double answer = distance(x[l], x[l + 1]);
        answer = min(answer, distance(x[l], x[r]));
        answer = min(answer, distance(x[l + 1], x[r]));
        return answer;
    }
    int m = (l + r) >> 1;
    int k1 = l, k2 = m + 1;
    for (int i = l; i <= r; i++)
    {
        if (y[i].id <= m)
            z[k1++] = y[i];
        else
            z[k2++] = y[i];
    }
    double d = closest(x, z, y, l, m);
    d = min(d, closest(x, z, y, m + 1, r));
    Merge(z, y, l, m, r);
    int k = l;
    for (int i = l; i <= r; i++)
        if (abs(y[i].x - x[m].x) < d)
            z[k++] = y[i];
    for (int i = l; i < k; i++)
        for (int j = i + 1; j < k && z[j].y - z[i].y < d; j++)
            d = min(d, distance(z[i], z[j]));
    return d;
}

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &x[i].x, &x[i].y);
        sort(x + 1, x + n + 1, cmpx);
        for (int i = 1; i <= n; i++)
            y[i] = x[i], y[i].id = i;
        sort(y + 1, y + n + 1, cmpy);
        double answer = closest(x, y, z, 1, n);
        printf("%.2f\n", answer / 2);
    }
    return 0;
}
