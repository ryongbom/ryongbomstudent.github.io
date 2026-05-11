// improvement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

int uklid(int a, int b)
{
	int r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while (r);
	return a;
}

int getDen(int n)
{
	int i;
	int den = 1;
	for (i = 2; i <= n; i++)
	{
		den *= i;
	}
	return den;
}

int getNum(int n)
{
	int i, j;
	int num = 0;
	for (i = 1; i < n; i++)
	{
		int temp = 1;
		for (j = 2; j <= n; j++)
		{
			if (j != i + 1)
				temp *= j;
		}
		if (i % 2 == 1)
			num += (temp * i);
		else
			num -= (temp * i);
	}

	return num;
}
int main()
{
	int n;
	scanf_s("%d", &n);
	
	int r = uklid(getDen(n), abs(getNum(n)));
	printf("%d/%d\n", getNum(n) / r, getDen(n) / r);
    return 0;
}

