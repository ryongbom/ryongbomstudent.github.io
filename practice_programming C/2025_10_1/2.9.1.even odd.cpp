// 2.9.1.even odd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a[10];
	int i, even, odd;

	for (i = 0, even = 0, odd = 0; i < 10; i++) {
		cin >> a[i];
		if (i % 2 == 0)
			even += a[i];
		else
			odd += a[i];
	}

	cout << "even=" << even << endl << "odd=" << odd << endl;

    return 0;
}

