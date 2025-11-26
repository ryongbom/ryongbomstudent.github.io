// 2.8.3. array2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int N, i, j, count, n;
	int a[10000] = { 0 };
	
	cin >> N;

	count = 0;
	for (i = 0; N > 0; i++)
	{
		a[i] = N % 10;
		N /= 10;
		count++;
	}

	cout << "0 1 2 3 4 5 6 7 8 9" << endl;

	for (i = 0; i < 10; i++)
	{
		n = 0;
		for (j = 0; j < count; j++)
		{
			if (a[j] == i)
				n++;
		}
		cout << n << " ";
	}

	cout << endl;
    return 0;
}

