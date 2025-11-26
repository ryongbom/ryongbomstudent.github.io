// place ab-ba.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, a, b;
	
	cin >> n;

	for (b = 10; b < 100; b++) {
		if ((9 * b - n) % 99 == 0) {
			a = (9 * b - n) / 99;
			if (a > 0 && a < 10) {
				cout << a * 100 + b << endl;
			}
		}
	}
    return 0;
}

