// 2.9.5.S.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, S;

	cin >> n;

	for (i = 2, S = 1; i <= n; i++) {
		if (i % 2 == 0)
			S += i;
		else
			S -= i;
	}
	cout << S << endl;
    return 0;
}

