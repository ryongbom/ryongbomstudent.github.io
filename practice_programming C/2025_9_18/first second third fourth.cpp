// first second third fourth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	float x;
	cin >> x;

	if (x >= 8.5)
		cout << "First" << endl;
	else if (x >= 6.5)
		cout << "Second" << endl;
	else if (x >= 4.5)
		cout << "Third" << endl;
	else
		cout << "Fourth" << endl;
    return 0;
}

