// circle r.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	float r, area;
	float PI = 3.14;
	scanf_s("%f", &area);

	r = area / PI / 2;

	printf_s("r=%f\n", r);
    return 0;
}

