// x y z.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int x, y, z;
	cin >> x >> y >> z;

	if (x >= y && x >= z)
		cout << x << endl;
	else if (y >= x && y >= z)
		cout << y << endl;
	else
		cout << z << endl;
    return 0;
}

