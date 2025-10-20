// 2.7.2 n cout.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	int i, n, sum;

	scanf_s("%d", &n);

	sum = 1;

	for (i = 1; i < n; i++) {
		sum += i;
	}
	printf("%d\n", sum);
    
	return 0;
}

