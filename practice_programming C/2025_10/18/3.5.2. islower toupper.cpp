// 3.5.2. islower toupper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{
	char str[100];
	int i;

	gets_s(str);

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && islower(str[i])) {
			str[i] = toupper(str[i]);
			putchar(str[i]);
		}
		if (isspace(str[i])) {
			putchar(str[i]);
			if (islower(str[i + 1]))
			{
				str[i + 1] = toupper(str[i + 1]);
			}
			putchar(str[i + 1]);
		}
		else if (islower(str[i]))
			putchar(str[i]);
	}

	printf("\n");
    return 0;
}

