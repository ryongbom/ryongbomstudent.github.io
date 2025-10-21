// improve_3.6.4.function_day_of_year.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int is_leap_year(int);
int day_of_year(int, int, int);

int main()
{
	int y, m, d;
	scanf_s("%d-%d-%d", &y, &m, &d);
	printf("%d", day_of_year(m, d, y));
	return 0;
}

int is_leap_year(int y)
{
	return (y % 4 == 0 || y % 100 == 0) && y % 400 != 0;
}

int day_of_year(int m, int d, int y)
{
	int i;
	int count = 0;
	int day_of_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (is_leap_year(y))
		day_of_month[1] = 29;

	for (i = 0; i < m - 1; i++)
		count += day_of_month[i];

	return count + d;
}


