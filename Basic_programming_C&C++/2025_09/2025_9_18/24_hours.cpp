// 24 hours.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	unsigned short int a, b, A;
	cin >> a >> b;

	if (a < 12) {
		cout << a << " " << b << " AM" << endl;
	}
	else {
		A = a - 12;
		cout << A << " " << b << " PM" << endl;
	}

    return 0;
}
