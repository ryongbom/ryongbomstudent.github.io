// 2.8.1 nm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, m, count, j;
	int a[100];

	cin >> n;
	cin >> m;

	count = 0;
	while (n > 0)
	{
		a[count++] = n % m;
		n /= m;
	}

	for (j = count - 1; j >= 0; j--)
	{
		cout << a[j];
	}
	cout << endl;
    return 0;
}

