// 3.4.1. upper lower.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>


int main()
{
	char c;
	scanf_s("%c", &c);

	if (isalpha(c)) {
		if (isupper(c))
			printf("Upper\n");
		else
			printf("Lower\n");
	}

	else
		printf("No\n");

    return 0;
}

