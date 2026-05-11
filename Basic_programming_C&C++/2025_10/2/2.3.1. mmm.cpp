// 2.3.1. mmm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, m, i, max, min, j;

	cin >> n >> m;

	for (i = 1; ; i++) {
		min = (i - 1) * n + 1;
		max = n * i;
		if (max > m)
			max = m;
		if (i % 2 == 1) {
			for (j = min; j <= max; j++) {
					cout << j << " ";
			}
		}
		else {
			for (j = max; j >= min; j--) {
					cout << j << " ";
			}
		}
		cout << endl;
		if (max >= m)
			break;
	}
    return 0;
}

