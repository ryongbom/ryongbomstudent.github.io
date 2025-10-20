// x agricultural chemicals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	float x, y;
	int i, n;
	cin >> x;

	n = 20;
	for (i = 0; x > 30; i++) {
		y = (n - 2) * x / 100;
		n = n + 1;
		x = y / n * 100;
//		if (x <= 30) {
//			cout << i << endl;
//			break;
//		}
	}

	cout << i << endl;
    return 0;
}

