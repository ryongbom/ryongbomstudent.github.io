// sum count.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int x, y, i;
	cin >> x >> y;
	int sum = 0;
	int count = 0;

	for (i = x; i <= y; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum += i;
			count++;
		}
	}
	cout << sum << " " << count << endl;

    return 0;
}

