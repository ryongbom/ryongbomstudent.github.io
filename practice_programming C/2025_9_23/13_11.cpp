// 13 11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, j;
	cin >> n;

	for (i = 1; i <= (n / 11); i++) {
		if ((n - (11 * i)) % 13 == 0) {
			j = (n - (11 * i)) / 13;
			cout << n << "=" << "13*" << j << "+11*" << i << endl;
			return 0;	//if (n - (11 * i)) % 13 == 0, use return 0; next end for().
		}
	}

	cout << "NO" << endl;	// because (n - (11 * i)) % 13 1= 0, printf("NO");
}
