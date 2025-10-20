// 2.2.2. print m n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main() {
	int n, m, i;

	while (1)
	{
		scanf_s("%d", &n);
		if (n == 0) break;
		scanf_s("%d", &m);

		for (i = 1; i < m && i < n; i++, n /= 10);
		if (i == m)
			printf_s("%d\n", n % 10);
		else
			printf_s("-1\n");
	}
	return 0;
}

