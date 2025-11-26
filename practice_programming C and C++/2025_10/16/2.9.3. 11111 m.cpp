// 2.9.3. 11111 m.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int m, i, num;

	cin >> m;

	num = 1;
	i = 1;
	while (1)
	{
		num = num * 10 + 1;
		i++;
		if (num % m == 0)
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << "-1" << endl;
    return 0;
}

