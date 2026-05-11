// 1. n 333.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, a, b, sum;

	cin >> n;

	a = n;
	sum = 0;

	while (a) {
		b = a % 1000;
		sum += b;
		a = a / 1000;
	}

	cout << sum << endl;

    return 0;
}

int main() {
	int n, sum;

	cin >> n;

	sum = 0;
	while (n) {
		sum += n % 1000;
		n = n / 1000;
	}

	cout << sum << endl;
}
