// 2.9.6. the day of the week.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int day, w, i;

	cin >> day >> w;

	for (i = 0; i < (3 * w - 2); i++)
		cout << " ";

	for (i = 1; i <= day; i++) {
		cout << i;
		if (i % 7 == (8 - w)) {
			if (i < 10)
				cout << endl << " ";
			else
				cout << endl;
		}
			
		else {
			if (i < 9)
				cout << "  ";
			else
				cout << " ";
		}
	}
    return 0;
}

