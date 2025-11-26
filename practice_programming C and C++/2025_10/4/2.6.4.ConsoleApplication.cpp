// 2.6.4.ConsoleApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define N 10000
using namespace std;


int main()
{
	int n, i, j, count;
	
	char a[N + 1];

	for (i = 2; i <= N; i++)
		a[i] = 1;

	for (i = 2; i <= N / 2; i++) {
		if (!a[i])
			continue;
		for (j = 2 * i; j <= N; j += i) {
			a[j] = 0;
		}
	}

	cin >> n;
	count = 0;
	for (i = 2; i <= n; i++) {
		if (!a[i]) {
			cout << i << " ";
			count++;
		
			if (count % 4 == 0)
				cout << endl;
		}
	}
    return 0;
}

