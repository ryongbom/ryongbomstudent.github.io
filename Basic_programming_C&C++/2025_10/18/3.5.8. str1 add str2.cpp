// 3.5.8. str1 add str2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define Max 1000


int main()
{
	char str[Max];
	char str1[Max];
	char str2[Max];
	char count[128] = { 0 };
	int i, j = 0, k;

	gets_s(str1, Max);
	gets_s(str2, Max);

	strcat_s(str1, str2);

	for (i = 0; str1[i]; i++)
	{
		if (isalpha(str1[i]))
		{
			str[j++] = str1[i];
		}
	}
	str[j] = 0;

//	printf("%s\n", str);

	for (i = 0; str[i]; i++)
	{
//		for (k = 0; k < 128; k++)
//		{
//			if (str[i] == k)
//				count[k]++;
//		}
		count[str[i]]++;
	}
/*	for (k = 0; k < 128; k++)
	{
		if (count[k] > 0)
			printf("%c:%d\n", k, count[k]);
	}*/

	for (k = 'A'; k <= 'Z'; k++)
	{
		if (count[k] > 0 || count[k + 32] > 0)
		{
			for (i = 0; i < count[k]; i++)
			{
				printf("%c", k);
			}
			if (count[k + 32] > 0)
			{
				for (j = 0; j < count[k + 32]; j++)
				{
					printf("%c", k + 32);
				}
				count[k + 32] = 0;
			}		
		}
	}

	printf("\n");
    return 0;
}

