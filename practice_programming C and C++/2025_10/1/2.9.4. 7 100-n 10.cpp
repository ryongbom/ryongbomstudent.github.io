// 2.9.4. 7 100-n 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i, j;

	cin >> n;

	for (i = 100, j = 0; i <= n; i++) {
		if (i % 7 == 0){
			cout << i;
			j++;
			if (j % 10 == 0)
				cout << endl;
			else
				cout << " ";
		}
	}
    return 0;
}

