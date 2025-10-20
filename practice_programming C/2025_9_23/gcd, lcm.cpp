// gcd, lcm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, b;
	int i;
	int gcd, lcm;

	cin >> a >> b;

	for (i = a; ; i--) {
		if (a % i == 0 && b % i == 0) {
			cout << "gcd=" << i << endl;
			break;
		}
	}
	for (i = a; ; i++) {
		if (i % a == 0 && i % b == 0) {
			cout << "lcm=" << i << endl;
			break;
		}
	}
    return 0;
}

