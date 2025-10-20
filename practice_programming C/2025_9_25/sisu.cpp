// sisu.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


//int main()
//{
//	int n, i, sisu;
//	cin >> n;
//
//	sisu = 1;
//
//	for (i = 2; i < n; i++) {
//		if (n % i == 0)
//			sisu = 0;
//		break;
//	}
//
//	if (sisu == 1)
//		cout << "sisu" << endl;
//	else if (sisu == 0)
//		cout << "no sisu" << endl;
//
//	return 0;
//}

int main()
{
	int n, i;

	cin >> n;

	for (i = 2; i < n; i++) {
		if (n % i == 0)
			break;
	}

	if (n == i)
		cout << "sisu" << endl;
	else
		cout << "no sisu" << endl;
	return 0;
}

