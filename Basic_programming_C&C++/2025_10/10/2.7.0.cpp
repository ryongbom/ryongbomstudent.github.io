// 2.7.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a, i, j, k;
	cin >> a;
	
	k = 1;
	for (i = 2; i <= a / 2; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			k += 2;
			if (k == a)
			{
				cout << k << "=" << j << "line" << ":" << i - j + 1 << "low" << endl;
				//printf("%d= %d?:%d?\n", k, j, i - j + 1);
				break;
			}
		}
	}
	return 0;
}
