// 3.7.example_array_phibo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int phibo(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return phibo(n - 1) + phibo(n - 2);
}

int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d\n", phibo(n));
    return 0;
}


