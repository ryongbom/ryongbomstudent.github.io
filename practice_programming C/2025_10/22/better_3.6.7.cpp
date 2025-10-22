#include "stdafx.h"
#include <stdio.h>
#include <cmath>

long long gcd(long long a, long long b)
{
	long long r;
	do
	{
		r = a % b;
		a = b;
		b = r;
	} while (r);
	return a;
}

int main()
{
	int n;
	scanf_s("%d", &n);

	long long num = 1;
	long long den = 2;

	for (int i = 3; i <= n; i++)
	{
		long long num_new = i - 1;
		long long den_new = i;

		if (i % 2 == 1)
			num_new = -num_new;

		long long bottom = den * den_new;
		long long top = num * den_new + num_new * den;

		long long r = gcd(llabs(top), bottom);

		num = top / r;
		den = bottom / r;
	}

	printf("%lld/%lld", num, den);
    return 0;
}
