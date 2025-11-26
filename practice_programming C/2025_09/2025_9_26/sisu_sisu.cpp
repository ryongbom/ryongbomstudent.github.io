// sisu_sisu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, j;
	cin >> n;

	for (j = 2; j < n; j++) {
		for (i = 2; i < j; i++) {
			if (j % i == 0)
				break;
		}
		if (j == i && n % j != 0) {
			if (j >(n - j))
				break;
			cout << n << " = " << j << " + " << n - j << endl;
		}
	}
	
	return 0;
}

