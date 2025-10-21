// 2.9.2. 321321 array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


/*int main(void)
{
	int array[1001];
	int n, i, j, temp, a, Sum;

	cin >> n;
	
	array[0] = 2;
	Sum = array[0];
	i = 1;
	a = 3;
	while (i < n)
	{
		if (a > 3)
			a = 1;
		temp = a;
		for (j = 0; j < i; j++)
		{
			temp = temp * 10;
		}
		array[i] = array[i - 1] + temp;
		Sum = Sum + array[i];

		i++;
		a++;
	}

	cout << Sum << endl;
    return 0;
}*/

int main()
{
	int n, carry, i;
	int num[3] = { 2, 3, 1 }, a[1001];

	cin >> n;

	carry = 0;
	for (i = 0; i < n; i++)
	{
		a[i] = carry + num[i % 3] * (n - i);
		carry = a[i] / 10;
		a[i] = a[i] % 10;
	}

	for (i = n - 1; i >= 0; i--)
		cout << a[i];
	cout << endl;

	return 0;
}

