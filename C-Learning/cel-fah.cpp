// cel-fah.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	float fah;
	float cel;

	scanf_s("%f", &cel);
	fah = cel * 9.0 / 5.0 + 32.0;

	printf_s("%f\n", fah);
    return 0;
}


