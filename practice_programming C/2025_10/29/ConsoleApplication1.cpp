// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char *p;
	char arr[] = { 'a', 'b', 'c', 'd', 'e', '\0' };
	p = arr;
	p += 2;
	printf("%c\n", *p);
	puts(p);
	return 0;
}

