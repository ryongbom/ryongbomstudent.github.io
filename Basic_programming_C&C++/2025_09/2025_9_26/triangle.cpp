// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, j;

	cin >> n;

	for (i = n; i >= 1; i--) {
		for (j = 0; j < (n - i) * 2; j++)
			cout << " ";
		if (i != 1) {
			for (j = 1; j <= i; j++) {
				cout << j << "-";
			}
			for (j = (i - 1); j >= 1; j--) {
				if (j != 1)
					cout << j << "-";
				else
					cout << j;
			}
		}
		else
			cout << i;
		cout << endl;
	}
    return 0;
}

