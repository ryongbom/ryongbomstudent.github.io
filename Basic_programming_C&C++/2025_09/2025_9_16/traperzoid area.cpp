// traperzoid area.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	float a, b, h, s;
	scanf_s("%f%f%f", &a, &b, &h);
	s = (a + b) * h / 2;
	printf_s("area=%f", s);
    return 0;
}

