// 2.3.2.nnn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, a;

	cin >> n;

	cout << n << "=";
	i = 2;
	a = n;
	while (i <= (n / 2)) {
		if (a % i == 0) {
			if (a != i)
				cout << i << "*";
			else
				cout << i << endl;
			a = a / i;
			continue;
		}
		else
			i++;
	}
    return 0;
}

