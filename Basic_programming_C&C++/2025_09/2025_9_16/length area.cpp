// length area.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	float r, s, l;
	float PI = 3.14;

	scanf_s("%f", &r);
	
	s = PI * r * r;
	l = 2 * PI * r;

	printf_s("length=%f\n", l);
	printf_s("area=%f\n", s);
    return 0;
}

