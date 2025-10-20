// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	unsigned short int n;
	cin >> n;

	if (n % 2 == 0 && n % 3 != 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
    return 0;
}

