// function_substr_r.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

/*void substr_r(const char origin[], char dest[], int count)
{
	int i, j = 0;
	int len = strlen(origin);
	if (len > count)
	{
		for (i = len - count; i < len; i++)
			dest[j++] = origin[i];
	}
	else
	{
		for (i = 0; i < len; i++)
			dest[j++] = origin[i];
	}
	dest[j] = '\0';
	return;
}*/

void substr_r(const char origin[], char dest[], int count)
{
	int len = strlen(origin);
	if (len <= count)
		strcpy(dest, origin);
	else
		strcpy(dest, origin + len - count);
	return;
}

int main()
{
	char str[1000], t[1000];
	int n;

	gets_s(str);
	scanf_s("%d", &n);
	substr_r(str, t, n);
	puts(t);
//	puts(str);
    return 0;
}

