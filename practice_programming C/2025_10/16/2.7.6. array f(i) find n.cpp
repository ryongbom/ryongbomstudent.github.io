// 2.7.6. array f(i) find n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, j, n, count;
	int f[100000] = {0};

	cin >> n;
	
	a = 1;
	count = 0;
	f[1] = 1;
	f[2] = 2;
	while (count < n)
	{
		for (j = 0; j < f[a]; j++)
		{
			count++;
			f[count] = a;
		}
		a++;
	}
	
	cout << f[count] << endl;
    return 0;
}

