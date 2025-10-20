// 1000 x.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned short int x;
	cin >> x;

	if (x >= 100)
		cout << 3 << endl;
	else if (x >= 10)
		cout << 2 << endl;
	else
		cout << 1 << endl;
    return 0;
}

