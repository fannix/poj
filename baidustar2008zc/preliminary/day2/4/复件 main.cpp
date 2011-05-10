#include <stdio.h>

const int maxLEN = 10 + 1;
const int maxVAL = 80 + 2;
const int GAP = 65536;

typedef long long INT;

int map[20];

INT f[6][maxVAL][65536];
INT g[6][maxVAL][65536];

INT X, Y, K;
char buf[maxLEN];
int len;

int
convert(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A' + 10;
	}
	else
	{
		return c - '0';
	}
}

INT
suming(int len)
{
	int j, k, t;
	INT sum = 0;
	INT MOD;
	if (len % 2 == 0)
	{
		for (j = 0; j < maxVAL; ++j)
		{
			for (k = 0; k < K; ++k)
			{
				sum += g[len / 2][j][k] * f[len / 2][j][K - k];
			}
		}
	}
	else
	{
		MOD = (1 << (4 * (len / 2)));
		for (t = 0; t < 16; ++t)
		{
			for (j = 0; j < maxVAL; ++j)
			{
				for (k = 0; k < K; ++k)
				{
					sum += g[len / 2][j][k] * f[len / 2][j][((K - k - t * MOD) % K + K) % K];
				}
			}
		}
	}
	return sum;
}

INT
get_count(char *x)
{
	int len = strlen(x);
	int i, t;
	INT sum = 0;
	for (i = 1; i < len; ++i)
	{
		sum += suming(i);
		for (t)

		


int main()
{
	int i, j, k, t;
	int MOD;

	scanf("%s", buf);
	for (i = 0; buf[i]; ++i)
	{
		map[convert(buf[i])] = 1;
	}
	scanf("%s", buf);
	for (K = 0, i = 0; buf[i]; ++i)
	{
		K = K * 16 + convert(buf[i]);
	}
	scanf("%s", buf);
	for (X = 0, i = 0; buf[i]; ++i)
	{
		X = X * 16 + convert(buf[i]);
	}
	scanf("%s", buf);
	for (Y = 0, i = 0; buf[i]; ++i)
	{
		Y = Y * 16 + convert(buf[i]);
	}

	if (K < 65536)
	{
		f[0][0][0] = 1;
		for (i = 0; i < 5; ++i)
		{
			for (j = 0; j < maxVAL; ++j)
			{
				for (t = 0; t < 16 && j + t < maxVAL; ++t)
				{
					if (map[t])
					{
						for (k = K - 1; k >= 0; --k)
						{
							f[i + 1][j + t][(k * 16 + t) % K] += f[i][j][k];
						}
					}
				}
			}
		}
		for (i = 1; i <= 5; ++i)
		{
			MOD = (1 << (4 * i - 4));
			for (j = 0; j < maxVAL; ++j)
			{
				for (t = 1; t < 16 && j - t >= 0; ++t)
				{
					for (k = 0; k < K; ++k)
					{
						g[i][j][k] += f[i - 1][j - t][k % MOD];
					}
				}
			}
		}

	}
	else
	{






