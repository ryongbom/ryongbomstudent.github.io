// 2.7.4. pibonachi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, a, b, i;

	cin >> n;

	a = 2;
	b = 1;
	for (i = 0; i < n; i++) {
		int temp = a + b;
		b = a;
		a = temp;
	}

	cout << a << "/" << b << endl;
    return 0;
}
