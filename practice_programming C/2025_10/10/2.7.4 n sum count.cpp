// 2.7.4 n sum count.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int i, j, n, sum, k;

	cin >> n;

	k = 1;
	i = 1;
	sum = 0;
	while (k <= n) {
		cout << "(";
		for (j = 0; j < k; j++, i += 2) {
			if (k == n)
				sum += i;
			if (j == k - 1)
				cout << i;
			else 
				cout << i << ", ";
		}
		if (k != n)
			cout << "), ";
		else
			cout << ")" << endl;
		k++;
	}

	cout << sum << endl;

    return 0;
}

