// 3.6.2.function_abs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int abs(int);

int main()
{
	printf("%d\n", abs(-4));
	printf("%d\n", abs(5));
    return 0;
}

/*int abs(int n)
{
	int temp;
	if (n >= 0)
	{
		temp = n;
		return temp;
	}
	else if (n < 0)
	{
		temp = -n;
		return temp;
	}
}*/

int abs(int n)
{
	if (n > 0)
		return n;
	else
		return -1 * n;
}

