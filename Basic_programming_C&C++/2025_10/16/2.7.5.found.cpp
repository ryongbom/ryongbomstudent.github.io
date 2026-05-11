// 2.7.5. found.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <iostream>
#define N 300000
using namespace std;


int main()
{
	int i, j, count;
	char a[N + 1];

	for (i = 2; i <= N; i++)
		a[i] = 1;

	for (i = 2; i < N / 2; i++)
	{
		if (!a[i])
			continue;
		for (j = 2 * i; j <= N; j += i)
		{
			a[j] = 0;
		}
	}

	count = 0;
	for (i = 2; i <= N; i++)
	{
		if (a[i])
			count++;
	}

	cout << count << endl;
    return 0;
}*/

#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int i, n, a_n, sum, k, count;
	//int j;
	cin >> n;

	k = 1;
	sum = 0;
	for (i = 1; i <= n; i++)
	{
		int a = (k + 1);
		for (count = 0; a > 0; count++)
		{
			a /= 10;
		}
		//a_n = k;
		//for (j = 1; j <= count; j++)
		//{
		//	a_n *= 10;
		//}
		//a_n = a_n + k + 1;
		a_n = pow(10, count) * k + k + 1;
		if (i % 2 == 1)
		{
			sum += a_n;
		}
		else
		{
			sum -= a_n;
		}
		k += 2;
	}

	cout << a_n << " " << sum << endl;
}
