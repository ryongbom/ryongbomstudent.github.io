// 3.5.6. array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define Max 1000

int main()
{
	char str[Max];
	char no_space[Max];
	int i, j, k;
	
	gets_s(str, sizeof(str));

	j = 0;
	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
			no_space[j++] = str[i];
	}
	no_space[j] = '\0';
	
	int len = strlen(no_space);

	for (j = 0; j < len - 1; j++)
	{
		for (k = 0; k < len - 1 - j; k++)
		{
			if (no_space[k] > no_space[k + 1])
			{
				char temp = no_space[k];
//				int temp = no_space[k + 1];
				no_space[k] = no_space[k + 1];
				no_space[k + 1] = temp;
			}
		}
	}

	printf("%s\n", no_space);
    return 0;
}

