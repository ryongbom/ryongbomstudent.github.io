// 3.6.7. it_is_important_function_for_me.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

int getNum(int);
int getDen(int);
int getNum1(int, int, int);
int getDen1(int, int);
int uclid(int, int);

int main()
{
	int n;
	int num, den, r;
	scanf_s("%d", &n);
	
	if (n % 2 == 0) {
		num = getNum(n);
		den = getDen(n);
		r = uclid(den, num);
		printf("%d/%d\n", num / r, den / r);
	}
	else
	{
		num = getNum1(n, getDen(n), getNum(n));
		den = getDen1(n, getDen(n));
		r = uclid(den, abs(num));
		printf("%d/%d\n", num / r, den / r);
	}

	return 0;
}

int getNum(int n)
{
	int N = n / 2;
	int i;
	int joint[10];

	for (i = 0; i < 10; i++)
	{
		joint[i] = (2 * i + 1) * (2 * i + 2);
	}

	int num = 0;
	int temp = 1;
	
	for (i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j != i)
				temp *= joint[j];
		}
		num += temp;
		temp = 1;
	}

	return num;
}

int getDen(int n)
{
	int N = n / 2;
	int i;
	int joint[10];

	for (i = 0; i < 10; i++)
	{
		joint[i] = (2 * i + 1) * (2 * i + 2);
	}

	int den = 1;

	for (i = 0; i < N; i++)
	{
		den *= joint[i];
	}

	return den;
}

int uclid(int a, int b)
{
	int r;
	do
	{
		r = a % b;
		a = b;
		b = r;
	} while (r);
	return a;
}

int getNum1(int n, int den, int num)
{
	return num * n - (n - 1) * den;
}
int getDen1(int n, int den)
{
	return den * n;
}
