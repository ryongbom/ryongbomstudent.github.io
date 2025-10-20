// over n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, sum;
	cin >> n;

	for (i = 1, sum = 0; ; i++) {
		sum = sum + i;
		if (sum > n) {
			cout << i << endl;
			break;
		}
	}
    return 0;
}

