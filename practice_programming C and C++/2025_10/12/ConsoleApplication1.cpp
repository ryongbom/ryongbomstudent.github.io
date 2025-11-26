// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <iostream>
using namespace std;


int main()
{
	int k;
	float x, eps, y, u;
	
	cout << "Input x; ";
	cin >> x;
	cout << "Input eps; ";
	cin >> eps;

	u = x;
	y = 0;
	k = 0;

	while (fabs(u) > eps) {
		y += u;
		k++;
		u = u * (-x) * k / (k + 1);
	}

	cout << "k = " << k << endl;
	cout << "y = " << y << endl;
    return 0;
}*/

/*#include <iostream>
using namespace std;

int main() 
{
	int n, i;
	float x, y, u;

	cout << "Input x; ";
	cin >> x;
	cout << "Input k; ";
	cin >> n;

	y = 0;
	u = x;

	for (i = 1; i <= n; i++) {
		y += u;
		u = u * (-x) * i / (i + 1);
	}

	cout << "y = " << y << endl;

	return 0;
}*/

#include <iostream>
using namespace std;

int main() 
{
	int n, i, j, k, sum, s;

	cin >> n;

	for (i = 2; i <= n; i++) {
		sum = 0;
		for (j = 1; j <= i / 2; j++) {
			if (i % j == 0)
				sum += j;
		}
		
		s = 0;
		for (k = 1; k <= sum / 2; k++) {
			if (sum % k == 0)
				s += k;
		}

		if (s == i && i != sum && sum < i)
			cout << sum << " " << s << endl;
	}

	return 0;
}
