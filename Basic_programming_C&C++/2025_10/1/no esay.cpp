// no esay.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int n, i, j, max, min;
	int a[4];
	//int temp[4];

	int last = 0;

	cin >> n;
	
	while(1) {
		last = n;
		for (i = 0; i < 4; i++) {
			a[i] = n % 10;
			n = n / 10;
		}

	/*	for (j = 0; j < 4; j++) {
			temp[j] = 0;
			if (j == 0) {
				for (i = 0; i < 4; i++) {
					if (temp[j] < a[i])
						temp[j] = a[i];
				}
			}
			else
				for (i = 0; i < 4; i++) {
					if (temp[j] < a[i] && a[i] < temp[j - 1])
						temp[j] = a[i];
				}
		}
	*/
		for (i = 0; i < 4; i++) {
			for (j = i + 1; j < 4; j++) {
				if (a[i] < a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
//					a[i] = a[j];
//					a[j] = a[i];
				}
			}
		}

		//max = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
		//min = temp[3] * 1000 + temp[2] * 100 + temp[1] * 10 + temp[0];

		max = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
		min = a[0] + 10 * a[1] + 100 * a[2] + 1000 * a[3];

		n = max - min;
		if (n != last)
			cout << max << " - " << min << " = " << n << endl;
		else break;
	}

	return 0;
}

