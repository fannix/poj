#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxN = 100000 + 10;

int n;
int p[maxN];
int bound;

int
exam(int len, int bound)
{
	int i;
	for (i = len; i <= n; ++i)
	{
		if (p[i] - p[i - len] >= bound)
		{
			return 1;
		}
	}
	return 0;
}

int
solve(int bound)
{
	int l, r, mid;
	l = 0;
	r = n - 1;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (exam(mid + 1, bound) == 0)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return l;
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", p + i);
		p[i] += p[i - 1];
	}
	scanf("%d", &bound);
	printf("%d\n", solve(bound));
	return 0;
}

