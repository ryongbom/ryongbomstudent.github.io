// 3.6.4.function_day_of_year.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int day_of_year(int, int, int);

int main()
{
	int y, m, d;
	scanf_s("%d-%d-%d", &y, &m, &d);
	printf("%d\n", day_of_year(m, d, y));
    return 0;
}

int day_of_year(int m, int d, int y)
{
	int temp;
	if ((y % 4 == 0 || y % 100 == 0) && y % 400 != 0)
		temp = 1;
	else
		temp = 0;	

	if (m <= 2)
		return 31 + d;
	else if (m <= 8 && m > 2 && m % 2 == 1)
	{
		if (temp)//(y % 4 == 0 || y % 100 == 0) && y % 400 != 0)
			return 29 + 31 * (m / 2) + 30 * (m / 2 - 1) + d;
		else
			return 28 + 31 * (m / 2) + 30 * (m / 2 - 1) + d;
	}
	else if (m <= 8 && m > 2 && m % 2 == 0)
	{
		if (temp)//(y % 4 == 0 || y % 100 == 0) && y % 400 != 0)
			return 29 + 31 * (m / 2) + 30 * (m / 2 - 2) + d;
		else
			return 28 + 31 * (m / 2) + 30 * (m / 2 - 2) + d;
	}
	else if (m > 8 && m % 2 == 1)
	{
		if (temp)//(y % 4 == 0 || y % 100 == 0) && y % 400 != 0)
			return 29 + 31 * (m / 2 + 1) + 30 * (m / 2 - 3) + d;
		else
			return 29 + 31 * (m / 2 + 1) + 30 * (m / 2 - 3) + d;
	}
	else if (m > 8 && m % 2 == 0)
	{
		if (temp)//(y % 4 == 0 || y % 100 == 0) && y % 400 != 0)
			return 29 + 31 * (m / 2) + 30 * (m / 2 - 2) + d;
		else
			return 28 + 31 * (m / 2) + 30 * (m / 2 - 2) + d;
	}
}



