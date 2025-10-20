// year, month.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	unsigned short int year, month;
	cin >> year >> month;
	if (year < 1 || month < 1 || month > 12) {
		cout << "no" << endl;
	}
	else {
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
				cout << 29 << endl;
			}
			else
				cout << 28 << endl;	
		}
		else {
			switch (month) {
			case 1: cout << 31 << endl; break;
			case 3: cout << 31 << endl; break;
			case 4: cout << 30 << endl; break;
			case 5: cout << 31 << endl; break;
			case 6: cout << 30 << endl; break;
			case 7: cout << 31 << endl; break;
			case 8: cout << 31 << endl; break;
			case 9: cout << 30 << endl; break;
			case 10: cout << 31 << endl; break;
			case 11: cout << 30 << endl; break;
			case 12: cout << 31 << endl; break;
			}
		}
		
	}
    return 0;
}

