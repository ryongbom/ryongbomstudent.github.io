// 2.1.1.n soro so.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


/*int main()
{
	int n, a, i;

	cin >> n;

	for (a = 2; a < n; a++) {
		for (i = 2; i <= a; i++) {
			if (n % i == 0 && a % i == 0)
				break;
		}
		if (i == (a + 1))
			cout << a << endl;
	}
    return 0;
}*/

int main() {
	int n, a, i, flag;

	cin >> n;

	for (a = 2; a < n; a++) {
		flag = 0;
		for (i = 2; i <= a; i++) {
			if (n % i == 0 && a % i == 0)
				flag = 1;
		}
		if (flag == 0)
			cout << a << endl;
	}
}
