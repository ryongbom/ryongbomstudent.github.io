// 3.5.7.add.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{
	char str1[100];
	char str2[100];
	char str_n[100];
	char n_str[100];
	int i, n, j, k = 0;

	gets_s(str1, sizeof(str1));
	gets_s(str2, sizeof(str2));
	scanf_s("%d", &n);

	j = 0;
	for (i = 0; i < n - 1; i++)
	{
		str_n[j++] = str1[i];
	}
	str_n[j] = '\0';

	for (i = n - 1; str1[i]; i++)
	{
		n_str[k++] = str1[i];
	}
	n_str[k] = '\0';

	strcat_s(str_n, str2);
	strcat_s(str_n, n_str);

	printf("%s\n", str_n);
    return 0;
}

/*int main()
{
	char str1[100];
	char str2[100];

	int i, j, n, len1, len2;

	gets_s(str1);
	gets_s(str2);

	scanf_s("%d", &n);

	len1 = strlen(str1);
	len2 = strlen(str2);

	for (i = len1 - 1; i >= n - 1; i--) {
			str1[i + len2] = str1[i];
	}
	for (i = 0; i < len2; i++){
		str1[n - 1 + i] = str2[i];
	}

	puts(str1);

	return 0;
}*/

