// 3.5.4. same.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1000


/*int main()
{
	char str[100], s[100];
	char a[128];

	int i, j, count = 0;

	gets_s(str);
	gets_s(s);

	for (i = 0; i < strlen(str); i++)
	{
		if (a[i]) 
		{
			for (j = 0; j < strlen(s); j++)
			{
				if (str[i] == s[j])
				{
					count++;
					a[str[i]] = 0;
				}
			}
		}
	}

	printf("%d", count);
    return 0;
}*/

int main()
{
	char str1[MAX], str2[MAX];
	char num1[128] = { 0 };
	char num2[128] = { 0 };
	int i, count;

	gets_s(str1);
	gets_s(str2);

	for (i = 0; str1[i]; i++)
	{
		num1[str1[i]] = 1;
	}

	for (i = 0; str2[i]; i++)
	{
		num2[str2[i]] = 1;
	}

	count = 0;
	for (i = 0; i < 128; i++)
	{
		if (num1[i] == 1 && num2[i] == 1)
		{
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}