// 3.6.5.function_num_digits(n).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int num_digits(int);

int main()
{
	int n;
	scanf_s("%d", &n);
	printf("%d\n", num_digits(n));
    return 0;
}

int num_digits(int n)
{
	int i;
	if (n > 0) {
		for (i = 0; n; i++) {
			n /= 10;
		}
		return i;
	}
	else
		return -1;
}
