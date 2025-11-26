// 2.9.2.2 3 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i;

	cin >> n;

	for (i = 0; i < n; i++) {
		if (i % 2 == 0 && i % 3 == 1)
			cout << i << " ";
	}
    return 0;
}

