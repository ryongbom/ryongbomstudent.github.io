// point_array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int *p = &a[0], *q = &a[9], temp;

	printf("Before: ");
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);

	while (p < q)
	{
		temp = *p;
		*p++ = *q;
		*q-- = temp;
	}

	printf("\nAfter:  ");
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	printf("\n");
    return 0;
}

