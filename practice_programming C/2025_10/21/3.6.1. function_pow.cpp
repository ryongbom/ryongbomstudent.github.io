// 3.6.1. function_pow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

double pow(double, int);

int main()
{
	double f = pow(2.5, 2);
	printf("%.2lf\n", f);
    return 0;
}

double pow(double a, int n)
{
	int i;
	double temp = 1;

	for (i = 0; i < n; i++)
	{
		temp *= a;
	}

	return temp;
}


