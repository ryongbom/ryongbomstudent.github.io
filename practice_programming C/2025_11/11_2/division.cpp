#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char num[1000];
	int N;
	gets(num);
	scanf("%d", &N);
	
	char *quo = (char*)malloc(strlen(num) + 1);
	char *n = (char*)malloc(strlen(num) + 1);
	int rem;
	char *p = quo;
	
	strcpy(n, num);
	
	int temp = 0;
	int carry = 0;
	
	while(*n)
	{
		temp = carry + *n - '0';
		*n++;
		while(temp < N)
		{
			temp *= 10;
			temp += *n++ - '0';
		}
		*p = temp / N + '0';
		carry = (temp % N) * 10;
		*p++;
	}
	rem = carry / 10;
	*p = 0;
	puts(quo);
	printf("%d", rem);
	
	free(n);
	free(quo);
	return 0;
}
