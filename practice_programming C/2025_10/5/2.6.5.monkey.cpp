// 2.6.5.monkey.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*#include <iostream>
#define max 1000
using namespace std;


int main()
{
	int n, m, i, j, remain;
	char monkey[max + 1];

	cin >> n;
	cin >> m;

	for (i = 0; i < n; i++)
		monkey[i] = 0;
	i = 0;
	j = 0;

	remain = n;

	while (remain > 1) {
		if (!monkey[i]) {
			j++;
			if (j == m) {
				monkey[i] = 1;
				j = 0;
				remain--;
			}
		}
		
		i = (i + 1) % n;
	}

	for (i = 0; i < n; i++) {
		if (!monkey[i])
			cout << i + 1 << endl;
	}
	return 0;
}*/

#include <iostream>
#define Max 1000
using namespace std;

int main() {
	int n, m, i, j, temp;
	char monkey[Max + 1];

	cin >> n;
	cin >> m;

	for (i = 1; i <= n; i++)
		monkey[i] = 1;

	i = 1;
	j = 0;
	
	temp = n;
	while (temp > 1) {
		if (monkey[i]) {
			j++;
			if (j == m) {
				monkey[i] = 0;
				j = 0;
				temp--;
			}
		}

		i = i % n + 1;
	}

	for (i = 1; i <= n; i++) {
		if (monkey[i])
			cout << i << endl;
	}
	return 0;
}
