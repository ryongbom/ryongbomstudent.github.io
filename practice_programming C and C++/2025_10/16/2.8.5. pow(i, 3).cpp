// 2.8.5. pow(i, 3).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int function(int b);

int main()
{
	int n, i, a, b, sum;

	cin >> n;

	for (i = 1; i <= n; i++)
	{
		sum = 0;
		a = i;
		while (a > 0)
		{
			b = a % 10;
			a = a / 10;
//			sum += pow(b, 3);
			sum += function(b);
		}
		if (sum == i)
			cout << i << " ";
	}
    return 0;
}

int function(int b)
{
	return b * b * b;
}