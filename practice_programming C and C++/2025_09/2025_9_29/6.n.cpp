// 6.n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, a, b, i;
	
	cin >> n;

	a = n;
	while (n) {
		b = a % 10;
		a = a / 10;
		for (i = 1; i <= b; i++) {
			cout << b;
			if (i == b)
				cout << endl;
		}
	}
    return 0;
}
