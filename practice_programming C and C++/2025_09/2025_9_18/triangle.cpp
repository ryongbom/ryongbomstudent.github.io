// triangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	float x, y, z;
	cin >> x >> y >> z;

	if (x < (y + z) && y < (x + z) && z < (x + y))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
		
    return 0;
}

