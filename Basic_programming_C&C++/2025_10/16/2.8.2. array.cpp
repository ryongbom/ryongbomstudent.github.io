// 2.8.2. array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int i, j, num, count;
	int a[10000];

	cin >> num;

	count = 0;
	for (i = 0; num > 0; i++)
	{
		a[i] = num % 10;
		num /= 10;
		count++;
	}
	//for (i = count - 1; i >= 0; i--)
	//{
	//	cout << a[i] << " ";
	//}

	for (i = count - 1; i >= 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			if (a[i] == a[j])
				cout << a[i] << " ";
		}
	}

	cout << endl;

    return 0;
}

