#include <stdio.h>

const int maxLEN = 10 + 1;
const int maxVAL = 80 + 2;
const int GAP = 65536;

typedef long long INT;

int map[20];

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

int
exam(INT x)
{
	int i;
	int sum;
	len = 0;
	for (; x > 0; x /= 16, ++len)
	{
		buf[len] = x % 16;
		if (map[buf[len]] == 0)
		{
			return 0;
		}
	}

	/*
	buf[len] = '\0';
	for (i = len - 1; i >= 0; --i)
	{
		if (buf[i] < 10)
		{
			printf("%c", buf[i] + '0');
		}
		else
		{
			printf("%c", buf[i] - 10 + 'A');
		}
	}
	printf("\n");
	*/

	sum = 0;
	for (i = 0; i < len / 2; ++i)
	{
		sum += buf[i];
	}
	for (i = (len + 1) / 2; i < len; ++i)
	{
		sum -= buf[i];
	}

	return sum == 0;
}

int main()
{
	INT i;
	INT sum;

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

	sum = 0;
	for (i = (X + K - 1) / K * K; i <= Y; i += K)
	{
		sum += exam(i);
	}

	printf("%I64d\n", sum);
	return 0;
}

