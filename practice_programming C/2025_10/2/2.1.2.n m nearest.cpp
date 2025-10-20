// 2.1.2.n m nearest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, m, i;

	cin >> n >> m;

	i = m / n;

	if ((m - i * n) > (n * i + n - m)) 
		cout << n * i + n << endl;
	else
		cout << i * n << endl;

    return 0;
}

