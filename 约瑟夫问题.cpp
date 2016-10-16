#include<stdio.h>
#include<string.h>
struct monkey
{
	int nextp;
	int no;
}link[1000000];
int main()
{
	int i, n, s, k, m, count = 0;
	scanf("%d,%d,%d", &n, &m, &s);
	if (n < 1 || m < 1 || s < 1)
	{
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}
	else if (m > n) {
		printf("k should not bigger than n.\n");
		return 0;
	}
	else {
		for (i = 1; i <= n; i++)
		{
			if (i == n)
				link[i].nextp = 1;
			else
				link[i].nextp = i + 1;
			link[i].no = i;
		}
		k = m - 1;
		while (count != n) {
			for (i = 0; i != s;) {
				k = link[k].nextp;
				if (link[k].no != 0)
					i++;
			}
			printf("%d", link[k].no);
			link[k].no = 0;
			if (++count % 10 == 0||count==n)
				printf("\n");
			else
				printf(" ");
		}
		return 0;
	}
}
