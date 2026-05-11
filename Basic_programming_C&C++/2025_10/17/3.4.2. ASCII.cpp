// 3.4.2. ASCII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int main()
{
	int a, b;
	char c;

	scanf_s("%d%c%d", &a, &c, &b);

	switch (c)
	{
	case '+': printf("%d", a + b); break;
	case '-': printf("%d", a - b); break;
	case '/': printf("%d", a / b); break;
	case '*': printf("%d", a * b); break;
	default:break;
	}

    return 0;
}

