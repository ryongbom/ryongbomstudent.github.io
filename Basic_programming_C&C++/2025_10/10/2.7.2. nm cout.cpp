// 2.7.2. nm cout.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <iostream>
using namespace std;


int main()
{
	int n, m, i, j, sum, a;

	cin >> n >> m;

	sum = 0;

	i = 1;
	a = 1;
	j = 0;
	while (j <= a && i <= m) {
		if (i < n) {
			j++;
			if (j == a) {
				j = 0;
				a++;
			}
			i++;
		}
		else {
			j++;
			i++;
			sum = sum + a;
			if (j == a) {
				j = 0;
				a++;
			}
		}
	}
	cout << sum << endl;

    return 0;
}*/

#include <iostream>
using namespace std;

int main() {
	int i, j, k, n, m, s;

	cin >> n >> m;

	k = 1;
	s = 0;
	for (i = 1; ; i++) {
		for (j = 0; j < i; j++) {
			if (k >= n)
				s += i;
			if (k >= m) {
				cout << s << endl;
				return 0;
			}
			k++;
		}
	}
	return 0;
}

