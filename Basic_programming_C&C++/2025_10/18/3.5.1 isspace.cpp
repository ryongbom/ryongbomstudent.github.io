// 3.5.1 isspace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	int len, i;
	char str[100];

	gets_s(str);
	
	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		if (!isspace(str[i]))
			putchar(str[i]);
	}
    return 0;
}
