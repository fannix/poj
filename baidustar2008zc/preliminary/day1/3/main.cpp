#include <stdio.h>
#include <math.h>
#include <set>
#include <algorithm>

using namespace std;

const int maxN = 100000 + 10;
const int maxNODE = 262144 + 10;

int n, m;
int A[maxN];
set<int> iset[maxNODE];

void
setup(int u, int l, int r)
{
	int i;
	if (l > r)
	{
		return;
	}
	for (i = l; i <= r; ++i)
	{
		iset[u].insert(-A[i]);
	}
	if (l == r)
	{
		return;
	}
	int mid = (l + r) / 2;
	setup(u * 2, l, mid);
	setup(u * 2 + 1, mid + 1, r);
}

void
update(int x, int y)
{
	int l, r, mid;
	int u;
	l = 1, r = n;
	u = 1;
	while (l <= r)
	{
		iset[u].erase(-A[x]);
		iset[u].insert(-y);

		if (l == r)
		{
			break;
		}

		mid = (l + r) / 2;
		if (x <= mid)
		{
			u = u * 2;
			r = mid;
		}
		else
		{
			u = u * 2 + 1;
			l = mid + 1;
		}
	}
	A[x] = y;
}

int
find(int u, int l, int r, int s, int t, int y)
{
	if (s <= l && t >= r)
	{
		set<int>::iterator p = iset[u].lower_bound(-y);
		if (p == iset[u].end())
		{
			return 0;
		}
		else
		{
			return -(*p);
		}
	}
	int mid = (l + r) / 2;
	int max = -1, temp;
	if (s <= mid)
	{
		if (max < (temp = find(u * 2, l, mid, s, t, y)))
		{
			max = temp;
		}
	}
	if (t > mid)
	{
		if (max < (temp = find(u * 2 + 1, mid + 1, r, s, t, y)))
		{
			max = temp;
		}
	}
	return max;
}

int
main()
{
	int i, s, t, x, y, opr;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", A + i);
	}
	setup(1, 1, n);
	for (i = 0; i < m; ++i)
	{
		scanf("%d", &opr);
		if (opr == 0)
		{
			scanf("%d %d", &x, &y);
			update(x, y);
		}
		else
		{
			scanf("%d %d %d", &s, &t, &y);
			printf("%d\n", find(1, 1, n, s, t, y));
		}
	}
	return 0;
}

