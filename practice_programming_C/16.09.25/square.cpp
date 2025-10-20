// square.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int a, b, s;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	s = a * b;
	printf_s("%d\n", s);
    return 0;
}

