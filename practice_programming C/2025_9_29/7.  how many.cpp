// 7.  how many.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, a, b, count;

	cin >> n;

	count = 0;
	
	for (i = 1; i <= n; i++) {
		a = i;
		while (a) {
			b = a % 10;
			if (b == 1) {
				count++;
				a = 0;
				break;
			}
			a = a / 10;
		}
	}
	cout << count << endl;
    return 0;
}

