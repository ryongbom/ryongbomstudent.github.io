// 2.6.3.ConsoleApplication.cpp : Defines the entry point for the console application.
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
		
		for (j = i * 2; j <= N; j += i) {
			a[j] = 0;
		}
	}

	cin >> n;

	for (i = 2; i <= n; i++) {
		for (j = 2; j * j < i; j++) {
			if (a[j] && i % j == 0 && a[i / j]) {
				cout << i << " ";
				break;
			}
		}
	}
    return 0;
}

