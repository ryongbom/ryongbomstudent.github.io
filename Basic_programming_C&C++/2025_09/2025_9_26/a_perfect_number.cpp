// a perfect number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, j, sum;
	
	cin >> n;

	for (i = 2; i <= n; i++) {
		for (j = 1, sum = 0; j <= (i / 2); j++) {
			if (i % j == 0)
				sum = sum + j;
		}
		if (sum == i)
			cout << i << " ";
	}
    return 0;
}
