#include "stdio.h"
#include "stdlib.h"

const int maxN = 128;
const double INF = 1e20;
const double eps = 1e-7;

struct NODE;
typedef NODE *pNODE;
struct NODE{
	int n;
	double flow, cap;
	double cost;
	pNODE next, other;
};

pNODE node[maxN];
pNODE pre[maxN];
int n,m,k;

int st[2][maxN],sn[2];
double cost[maxN];
int check[maxN];
int p,q;

double A[maxN], B[maxN];
double V[maxN][maxN], C[maxN][maxN];

void
bellmanford(int s, int n)
{
	int u, i, t;
	pNODE pp;
	for (i = 0; i <= n; ++i)
	{
		cost[i] = INF;
		check[i] = 0;
	}
	p = 0, q = 1;
	sn[p] = sn[q] = 0;
	st[p][sn[p]++] = s;
	cost[s] = 0;
	for (i = 2; i <= n; ++i)
	{
		if (sn[p] == 0)
		{
			break;
		}
		sn[q] = 0;
		while (sn[p])
		{
			u = st[p][--sn[p]];
			for (pp = node[u]; pp ;pp = pp->next)
			{
				if (pp->flow < pp->cap && cost[u] + pp->cost < cost[pp->n])
				{
					cost[pp->n] = cost[u] + pp->cost;
					pre[pp->n] = pp->other;
					if (check[pp->n] != i)
					{
						st[q][sn[q]++] = pp->n;
						check[pp->n] = i;
					}
				}
			}
		}
		t = p; p = q; q = t;
	}
}

void
fixflow(int s, int t, double &mincost)
{
	int i;
	double mingap = INF;
	for (i = t; i != s; i = pre[i]->n)
	{
		if (mingap > pre[i]->other->cap - pre[i]->other->flow)
		{
			mingap = pre[i]->other->cap - pre[i]->other->flow;
		}
	}
	for (i = t; i != s; i = pre[i]->n)
	{
		pre[i]->other->flow += mingap;
		pre[i]->flow = -pre[i]->other->flow;
	}
	mincost += mingap * cost[t];
}

double
mincost_maxflow(int s, int t, int n)
{
	double mincost = 0.0;
	for (;;)
	{
		bellmanford(s, n);
		if (cost[t] >= INF)
		{
			break;
		}
		fixflow(s, t, mincost);
	}
	return mincost;
}

void
connect(int u, int v, double cap, double cost)
{
	pNODE p1,p2;
	p1 = (pNODE)malloc(sizeof(NODE));
	p1->n = v;
	p1->cap = cap;
	p1->cost = cost;
	p1->flow = 0.0;
	p1->next = node[u];
	node[u] = p1;

	p2 = (pNODE)malloc(sizeof(NODE));
	p2->n = u;
	p2->cap = 0.0;
	p2->cost = -cost;
	p2->flow = 0.0;
	p2->next = node[v];
	node[v] = p2;

	p1->other = p2;
	p2->other = p1;
}

void init(int n)
{
	pNODE p;
	int i;
	for (i = 0; i <= n; ++i)
	{
		while (node[i])
		{
			p = node[i]->next;
			free(node[i]);
			node[i] = p;
		}
	}
}

void
construct(double y)
{
	int i, j;
	pNODE p, pp;
	for (i = 1; i <= n; ++i)
	{
		for (p = node[i]; p; p = p->next)
		{
			if (p->n != 0)
			{
				j = p->n - n;

				p->flow = 0.0;
				p->cost = y * C[i][j] - V[i][j];

				pp = p->other;
				pp->flow = 0.0;
				pp->cost = -p->cost;
			}
		}
	}
	for (p = node[0]; p; p = p->next)
	{
		p->flow = 0.0;
		
		pp = p->other;
		pp->flow = 0.0;
	}
	for (pp = node[n + m + 1]; pp; pp = pp->next)
	{
		p = pp->other;
		p->flow = 0;

		pp->flow = 0;
	}
}		

double
solve()
{
	int i, j;
	double l, r, mid;

	l = 0.0, r = 1.0;

	for (;;)
	{
		construct(r);
		if (mincost_maxflow(0, n + m + 1, n + m + 2) >= eps)
		{
			break;
		}
		l = r;
		r *= 2;
	}

	while (r - l >= 5e-5)
	{
		mid = (l + r) / 2;
		construct(mid);
		if (mincost_maxflow(0, n + m + 1, n + m + 2) >= eps)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	return l;
}

int
main()
{
	int i, j;
	double sum = 0.0;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%lf", A + i);
		sum += A[i];
		connect(0, i, A[i], 0.0);
	}
	for (i = 1; i <= m; ++i)
	{
		scanf("%lf", B + i);
		sum -= B[i];
		connect(n + i, n + m + 1, B[i], 0.0);
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			scanf("%lf", V[i] + j);
		}
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			scanf("%lf", C[i] + j);
		}
	}

	if (sum > eps)
	{
		printf("-1\n");
		return 0;
	}

	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			connect(i, n + j, INF, 0.0);
		}
	}
	printf("%.3lf\n", solve());
	return 0;
}

