// 1000 sisu n.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i;
	for (n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {
			if (n % i == 0)
				break;
		}
		if (n == i)
			cout << n << " ";
	}
    return 0;
}
