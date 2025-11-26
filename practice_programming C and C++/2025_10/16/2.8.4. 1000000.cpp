// 2.8.4. 1000000.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
const int N = 1000000;
using namespace std;


/*int main()
{
	int i, j, k, n;

	cin >> n;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= i / 2; j++)
		{
			if (i % j == 0 && j == i / j)
			{
				for (k = 1; k <= (i + n) / 2; k++)
				{
					if ((i + n) % k == 0 && k == (i + n) / k)
						cout << i << " ";
				}
			}
		}
	}

	cout << endl;

    return 0;
}*/

int main(void)
{
	int i, j, n;

	cin >> n;

	for (i = 1; i * i <= N; i++)
	{
		for (j = i + 1; j * j < i * i + n; j++);
		
		if (j * j == i * i + n)
			cout << i * i << endl;
	}

	return 0;
}

