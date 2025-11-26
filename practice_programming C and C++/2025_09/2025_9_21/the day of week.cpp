// the day of week.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	unsigned short int d, w;
	cin >> d >> w;
    
	switch ((d - w - 1) % 7 - 1) {
		case 0: cout << "Sun" << endl; break;
		case 1: cout << "Sat" << endl; break;
		case 2: cout << "Fri" << endl; break;
		case 3: cout << "Thi" << endl; break;
		case 4: cout << "Wed" << endl; break;
		case 5: cout << "Tue" << endl; break;
		case 6: cout << "Mon" << endl; break;
		default: break;
		}
    return 0;
}

