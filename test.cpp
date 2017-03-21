#include <iostream>
#include <cmath>
#include<math.h>
#include<algorithm>
using namespace std;

struct Point
{
	int ID;
	double x, y;
}X[100001],Y[100001],Z[100001];
double distance(Point p1,Point p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx*dx + dy*dy);
}
bool cmpx(Point p1, Point p2)
{
	return p1.x < p2.x;
}

bool cmpy(Point p1, Point p2)
{
	return p1.y < p2.y;
}

void Merge(Point x[], Point y[], int l, int m, int r)
{
	int i, j, k;
	i = l;j = m + 1;k = l;
	while (i <= m&&j <= r)
	{
		if (x[i].y < x[j].y)
			y[k++] = x[i++];
		else
			y[k++] = x[j++];
	}
	while (i <= m)
	{
		y[k++] = x[i++];
	}
	while (j <= r)
	{
		y[k++] = x[j++];
	}
}
double closest(Point x[], Point y[], Point z[], int l, int r)
{
	if (r - 1 == 1)
	{
		double d = distance(x[r], x[l]);
		return d;
	}
	if (r - 1 == 2)
	{
		double d1 = distance(x[l], x[l + 1]);
		double d2 = distance(x[l + 1], x[r]);
		double d3 = distance(x[l], x[r]);
		if (d1 < d2&&d1 < d3)
			return d1;
		else if (d2 < d3)
			return d2;
		else
			return d3;
	}
	int m = (1 + r) / 2;
	int f = l, g = m + 1;
	for (int i = l; i <= r; i++)
	{
		if (y[i].ID <= m)
			z[f++] = y[i];
		else
			z[g++] = y[i];
	}
	double d = closest(x, z, y, l, m);
	d = min(d, closest(x, z, y, m+1, r));
	Merge(z, y, l, m, r);
	int k = l;
	for (int i = l; i <= r; i++)
	{
		if (abs(y[i].x - x[m].x) < d)
			z[k++] = y[i];
	}
	for (int i = l; i < k; i++)
	{
		for (int j = i + 1; j < k && z[j].y - z[i].y < d; j++)
			d = min(d, distance(z[i], z[j]));
	}
	return d;
}
int main()
{
	int n;
	while (scanf("%d", &n), n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &X[i].x, &X[i].y);
		}
		sort(X + 1, X + n + 1, cmpx);
		for (int i = 1; i <= n; i++)
		{
			Y[i] = X[i];
			Y[i].ID = i;
		}
		sort(Y + 1, Y + n + 1, cmpy);
		int l = 1;
		int r = n;
		double ans = closest(X, Y, Z, l, r);
		printf("%.2lf\n", ans / 2);
	}
	return 0;
}
