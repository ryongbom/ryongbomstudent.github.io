#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	char str1[1000];
	char str2[1000];
	int i;
	
	gets(str1);
	gets(str2);
	
	for (i = 0; str1[i]; i++)
	{
		if (isspace(str1[i]))
			continue;
		if (strchr(str2, str1[i]))
			continue;
		printf("%c", str1[i]);
	}
	return 0;
}
