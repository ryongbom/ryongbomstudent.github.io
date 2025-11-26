// sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, sum, i, Sum;
	cin >> n;

	for (i = 1, sum = 0, Sum = 0; i <= n; i++) {
		sum += i;
		Sum += sum;
	}

	cout << Sum << endl;
    return 0;
}

