// equation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int x, y;
	cin >> x;

	if (x < 0) {
		y = x + 10;
		cout << y << endl;
	}
	else if (x >= 0 && x < 15) {
		y = 3 * x + 5;
		cout << y << endl;
	}
	else {
		y = 2 * x - 10;
		cout << y << endl;
	}
    return 0;
}

