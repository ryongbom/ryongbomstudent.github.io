// 2.8.6. n_k.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, k, i, a, b;
	int count = 0;

	cin >> n >> k;

	for (i = 1; i <= n; i++)
	{
		a = i;
		while (a > 0)
		{
			b = a % 10;
			a /= 10;
			if (k == b)
				count++;
		}
	}

	cout << count << endl;

    return 0;
}

