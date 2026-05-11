// 2.9.2.array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, a;

	cin >> n;

	for (i = 0, a = 1; i < n; i++) {
		cout << a << " ";
		a = a * 2;
	}
    return 0;
}

