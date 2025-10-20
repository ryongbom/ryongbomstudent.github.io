// sum 1-n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	unsigned short int n, i, Sum;
	cin >> n;

	for (i = 0, Sum = 0; i <= n; i++) {
		Sum += i;
	}
	cout << Sum << endl;
    return 0;
}

