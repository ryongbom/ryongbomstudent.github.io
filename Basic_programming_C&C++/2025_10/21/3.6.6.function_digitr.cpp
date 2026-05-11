// 3.6.6.function_digitr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define Max 1000

int digitr(long, int);
int digitl(long, int);

int main()
{
	int k;
	long n;
	scanf_s("%d%d", &n, &k);
	printf("%d\n%d\n", digitr(n, k), digitl(n, k));
    return 0;
}

int digitr(long n, int k)
{
	int num[Max];
	int i, count = 0;
	for (i = 0; n; i++)
	{
		num[i] = n % 10;
		n /= 10;
		count++;
	}
	return num[k - 1];
}

int digitl(long n, int k)
{
	int num[Max];
	int i, count = 0;
	for (i = 0; n; i++)
	{
		num[i] = n % 10;
		n /= 10;
		count++;
	}
	return num[count - k];
}
