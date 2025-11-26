// marks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	float a[100];
	int n, i;
	float sum, average;

	cin >> n;

	for (i = 1, sum = 0; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	average = sum / n;

	for (i = 1; i <= n; i++) {
		if (a[i] > average)
			cout << a[i] << " ";
	}
    return 0;
}

