#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[1000];
	char s[1000];
	int size;
	int i;
	int count = 1;
	
	gets(str);
	scanf("%d", &size);
	char temp = str[0];
	
	for (i = 1; i <= strlen(str) - size; i++)
	{
		if (str[i] < temp)
		{
			temp = str[i];
			count = i;
		}
	}
	int j = 0;
	while(j < size)
	{
		s[j++] = str[count++];
	}	
	s[j] = '\0';
	puts(s);
	return 0;
}
