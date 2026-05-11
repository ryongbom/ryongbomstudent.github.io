// function_trim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim_l(char str[]) {
	int i = 0;
	int count = 0;
	for (i = 0; ; i++)
	{
		if (isspace(str[i]))
			count++;
		else
			break;
	}
	puts(str + count);
}

void trim_r(char str[]) {
	int i;
	int len = strlen(str);
	for (i = len - 1; i >= 0; i--)
	{
		if (isspace(str[i]))
			str[i] = '\0';
		else
			break;
	}
	return;
}


int main()
{
	char s[1000];
	gets_s(s);
	trim_r(s);
	trim_l(s);
    return 0;
}

