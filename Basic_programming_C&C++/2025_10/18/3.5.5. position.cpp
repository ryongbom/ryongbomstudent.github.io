// 3.5.5. position.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	char str[100];
	char ch;
	int i;

	gets_s(str, sizeof(str));
	scanf_s("%c", &ch);

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ch)
		{
			printf("%d\n", i + 1);
			return 0;
		}
	}

	printf("No\n");

    return 0;
}

