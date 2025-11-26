// 2.6.2.ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#define N 1000000


int main()
{
	int i, j, n, count;

	scanf_s("%d", &n);

	char a[N + 1];

	for (i = 1; i <= n; i++)
		a[i] = 1;

	for (i = 2; i <= n / 2; i++) {
		if (!a[i])
			continue;
		for (j = 2 * i; j <= n; j += i) {
			a[j] = 0;
		}
	}

	count = 0;
	for (i = 5; i <= n; i++) {
		if (a[i] && a[i / 2])//if a[i] is sisu, it means i is holsu. so i / 2 == (i - 1) / 2
			count++;
	}

	printf("%d\n", count);
    return 0;
}
