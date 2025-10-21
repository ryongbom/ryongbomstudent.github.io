// 3.6.3.funtion_isPrime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int isPrime(int);

int main()
{
	if (isPrime(13))
		printf("13 is prime.\n");
	else
		printf("13 is composite.\n");
    return 0;
}

int isPrime(int n)
{
	int i;

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
