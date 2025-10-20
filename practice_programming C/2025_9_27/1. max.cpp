// 1. max.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include <iostream>
//using namespace std;


//int main()
//{
//	int a[1000];
//	int i, max = 0;

//	for (i = 0; ; i++) {
//		cin >> a[i];
//		if (a[i] > max)
//			max = a[i];
//		if (a[i] == 0)
//			break;
//	}

//	cout << max << endl;
//    return 0;
//}

#include <stdio.h>
int main()
{
	int n, max = 0;
	do
	{
		scanf_s("%d", &n);
		if (max < n)
			max = n;
	} while (n);
	printf_s("%d", max);
	return 0;
}
