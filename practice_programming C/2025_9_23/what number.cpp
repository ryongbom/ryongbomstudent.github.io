// what number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i;
	int arr[10];

	cin >> n;

	for (i = 1; i <= 10; i++) {
		cin >> arr[i];
		if (arr[i] == n)
			cout << i << endl;
	}
    return 0;
}

