// max.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a[10];
	int i, temp;
	for (i = 1; i <= 10; i++) {
		cin >> a[i];
	}

	temp = a[0];
	for (i = 1; i < 10; i++) {
		if (temp < a[i]) {
			temp = a[i];
		}
	}
	cout << temp << endl;
    return 0;
}

