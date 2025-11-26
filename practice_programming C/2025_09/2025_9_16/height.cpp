// height.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	float a, b, c;
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	c = b / a;
	printf_s("height=%fm", c);
    return 0;
}

