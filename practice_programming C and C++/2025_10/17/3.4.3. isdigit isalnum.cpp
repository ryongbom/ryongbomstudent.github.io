// 3.4.3. isdigit isalnum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>


int main()
{
	int i;
	char ch;

	for (i = 0; i <= 5; i++) {
		ch = getchar();
		if (!isalnum(ch) && ch != '_') {
			printf("No\n");
			return 0;
		}

		if (i == 0 && isdigit(ch)) {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

    return 0;
}

