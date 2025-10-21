// 2.9.1. dem, num 50.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int digit[50];
	int dem, num, i, pre;
	
	cin >> dem >> num;

	pre = dem / num;
	dem = (dem % num) * 10;
	if (dem == 0)
		cout << pre << endl;
	else
	{
		i = 0;
		while (i < 50)
		{
			digit[i] = dem / num;
			dem = (dem % num) * 10;
			if (dem == 0)
				exit(0);
			i++;
		}

		cout << pre << ".";
		for (i = 0; i < 50; i++)
			cout << digit[i];
	}
	
    return 0;
}

