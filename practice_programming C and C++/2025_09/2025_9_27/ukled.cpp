// ukled.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, b, i;

	cin >> a >> b;

	do
	{
		i = a % b;
		a = b;
		b = i;
	} while (i != 0);
	
	cout << a << endl;

    return 0;
}

