// 3. ball 100 h.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, i;
	float s, h;
	cin >> n;
	if (n == 1) {
		s = 100;
		cout << s << endl;
	}
	else {
		for (i = 2, s = 100, h = 100; i <= n; i++) {
			h = h / 2;
			s = s + (h * 2);
		}
		cout << s << endl;
	}
    return 0;
}

