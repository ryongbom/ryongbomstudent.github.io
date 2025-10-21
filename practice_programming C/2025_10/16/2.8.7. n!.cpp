// 2.8.7. n!.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


/*int main()
{
	int n, i, a, area, count;

	cin >> n;

	area = 1;
	for (i = 1; i <= n; i++)
		area = area * i;
	cout << area;

	count = 0;
	while (area > 0)
	{
		a = area % 10;
		area /= 10;
		if (a == 0)
			count++;
	}
	cout << count << endl;
		
    return 0;
}*/

int main(void)
{
	int n, i, j, count;

	cin >> n;

	count = 0;
	for (i = n; i > 0; i--)
	{
		j = i;
		while (j % 5 == 0)
		{
			j /= 5;
			count++;
		}
	}

	cout << count << endl;
}

