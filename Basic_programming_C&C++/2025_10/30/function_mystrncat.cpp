#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *mystrncat(char *str1, const char *str2, int size)
{
	char *str = str1;
	while (*str1)
		str1++;
	while (*str2 && size)
	{
		*str1++ = *str2++;
		size--;
	}
	*str1 = 0;
	return str;
}

int main()
{
	char p[100] = "my";
	mystrncat(p, "computerversion", 8);
	puts(p);
	free(p);
	return 0;
}
