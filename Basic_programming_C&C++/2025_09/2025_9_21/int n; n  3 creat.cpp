// int n; n  3 creat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//int main()
//{
//	unsigned short int n, i;
//	cin >> n;
//	for (i = 1; 3 * i <= n; i++) {
//		cout << 3 * i << " ";
//	}
//    return 0;
//}

int main() {
	unsigned short int n, i;
	cin >> n;

	i = 1;
	while (3 * i <= n) {
		printf_s("%d ", 3 * i);
		i = i + 1;
	}
	return 0;
}
