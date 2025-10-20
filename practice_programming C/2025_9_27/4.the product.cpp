// 4.the product.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, a, b, i;
	
	cin >> n;
	a = n;
	i = 1;
	while (a >= 10) {
		b = a % 10;
		a = a / 10;
		if (b % 2 == 0)
			i = i * b;
	}
	cout << i << endl;
    return 0;
}

