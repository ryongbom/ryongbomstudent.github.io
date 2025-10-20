// 2.2.1.a n m the remainder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, n, m, i, k;
	cin >> a >> n >> m;

	for (i = 0, k = 1; i < n; i++) {
		k = k * a;
		k = k % m;
	}

	cout << k << endl;

    return 0;
}

int main() {
	int a, n, m, i, product;

	cin >> a >> n >> m;

	for (i = 0, product = 1; i < n; i++) { /*the error because product over area*/
		product = product * a;
	}

	cout << product % m << endl;
	return 0;
}