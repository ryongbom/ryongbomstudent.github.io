// in the reverse order.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a[10];
	int i;

	for (i = 1; i <= 10; i++) {
		cin >> a[i];
	}

	for (i = 10; i >= 1; i--) {
		cout << a[i] << " ";
	}
    return 0;
}

