// h figure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int h, i, j, z;

	cin >> h;

	for (i = h; i >= 1; i--) {
		for (j = 1; j <= (2 * i - 1); j++) {
			cout << "*";
		}
		cout << endl;
		for (z = 0; z <= (h - i); z++)
			cout << " ";
	}
    return 0;
}

