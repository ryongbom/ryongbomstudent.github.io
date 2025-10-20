// money bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	float a, b;
	scanf_s("%f", &a);

	b = 1.05 * 1.05 * 1.05 * a;

	printf_s("money=%f\n", b);
    return 0;
}

