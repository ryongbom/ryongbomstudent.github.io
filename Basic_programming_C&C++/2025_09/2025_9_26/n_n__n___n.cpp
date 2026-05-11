// n_n__n___n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n, i, j, z, sum;

	cin >> n;

	for (i = 1; i <= n; i++) {
		for (j = 1, sum = 0, z = 0; j < i; j++) {
			z = 2 * j - 1;
			sum = sum + z;
		}
		for (j = 1; j <= sum; j++) {
			cout << " ";
		}
		for (j = 1; j <= (2 * i - 1); j++) {
			cout << "*";
		}
		cout << endl;
	}
    return 0;
}

