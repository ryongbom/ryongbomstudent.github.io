// product 1-n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	unsigned short int n, product, i;
	cin >> n;
	
	for (i = 1, product = 1; i <= n; i++) {
		product *= i;
	}
	cout << product << endl;
    return 0;
}

