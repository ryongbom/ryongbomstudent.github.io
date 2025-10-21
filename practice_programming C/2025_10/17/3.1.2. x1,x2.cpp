// 3.1.2. x1,x2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>


int main()
{
	float a, b, c, D, x1, x2;

	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &c);

	D = b * b - 4 * a * c;
	if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		printf("%0.2f", x1);
		printf(" %0.2f\n", x2);
	}
	else if (D == 0)
	{
		x1 = x2 = (-b) / (2 * a);
		printf("%0.2f %0.2f\n", x1, x2);
	}
	else
	{
		printf("No\n");
	}
    return 0;
}

