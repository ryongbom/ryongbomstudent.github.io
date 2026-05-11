// 3.5.10. number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
/*#define Max 1000


int main()
{
	char f[Max];
	char f1[Max];
	int i, j = 0, n, count = 0;

	gets_s(f);

	for (i = 0; f[i]; i++)
	{
		if (f[i] > 32)
		{
			f1[j++] = f[i];
		}
		if (f[i] == 32) {
			n = f[i + 1] - 48;
			break;
		}
	}

	f1[j] = '\0';

//	printf("%s\n", f1);
//	printf("%d\n", n);
 
	for (j = 0; f1[j]; j++)
	{
		count++;
		if (f1[j] == '.')
			break;
	}

//	printf("%d\n", count);

	for (j = 0; f1[j]; j++)
	{
		if (j < count + n - 1)
		{
			printf("%c", f1[j]);
		}
		if (j == count + n - 1)
		{
			if (f1[count + n] >= '5')
			{
				f1[j] = f1[j] + 1;
				//printf("%c", f1[j]);
				for (int pos = (count + n - 1); pos >= count; pos--)
				{
					if (f1[pos] != 58) {
						printf("%c", f1[pos] + 1);
						break;
					}
					else {
						f1[pos] = '0';
						printf("%c", f1[pos]);
						f1[pos - 1] = f1[pos - 1] + 1;
					}
				}

			}
			

			else
				printf("%c", f1[j]);
			break;
		}
	}

	printf("\n");

	return 0;
}*/

int main()
{
	char format[20];
	double f;
	int n;

	scanf_s("%lf", &f);
	scanf_s("%d", &n);

	snprintf(format, sizeof(format), "%%.%df", n);
	printf(format, f);

	return 0;
}
