// yes no.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;

	if (n % 2 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
    return 0;
}

