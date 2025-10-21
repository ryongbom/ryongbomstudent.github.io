// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#define Max 1000

int main()
{
	char str1[Max], str2[Max];
	int count[128] = { 0 };
	int i, j;

	gets_s(str1, Max);
	gets_s(str2, Max);

	for (i = 0; str1[i]; i++)
		if (isalpha(str1[i])) count[str1[i]]++;
	for (i = 0; str2[i]; i++)
		if (isalpha(str2[i])) count[str2[i]]++;

	for (i = 0; i < 26; i++) {
		for (j = 0; j < count['A' + i]; j++)
			printf("%c", 'A' + i);
		for (j = 0; j < count['a' + i]; j++)
			printf("%c", 'a' + i);
	}

	printf("\n");
	return 0;
}


