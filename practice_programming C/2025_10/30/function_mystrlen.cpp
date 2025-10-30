#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//int mystrlen(const char *str)
//{
//	const char *s = str;
//	while (*s)
//		s++;
//	return s - str;
//}

int mystrlen(const char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

int main()
{
	char str[100] = "student";
  	int len = mystrlen(str);
  	printf("%d\n", len);
  	return 0;
}
