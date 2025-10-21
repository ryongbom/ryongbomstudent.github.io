// 3.5.3. flag.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


/*int main()
{
	char str[100];
	int count, i, j;
	int flag[100];

	gets_s(str);

	for (i = 0; i < strlen(str); i++)
	{
		flag[i] = 1;
	}
	
	count = 1;
	for (i = 0; str[i]; i++)
	{
		if (flag[i])
		{
			for (j = i + 1; str[j]; j++)
			{
				if (str[i] == str[j])
				{
					count++;
					flag[j] = 0;
				}
			}
			printf("%c:%d\n", str[i], count);
			count = 1;
		}
	}

    return 0;
}*/

int main()
{
	char str[100];
	char count[128] = { 0 };
	int i;

	gets_s(str);

	for (i = 0; str[i]; i++) {
		count[str[i]]++;
	}

	for (i = 0; i < 128; i++) {
		if (count[i] > 0)
			printf("%c:%d\n", i, count[i]);
	}

	return 0;
}
