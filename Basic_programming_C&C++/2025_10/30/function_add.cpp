#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *add(const char *str1, const char *str2, char *result)
{
	char *pstr1 = (char*)malloc(strlen(str1));
	char *pstr2 = (char*)malloc(strlen(str2));
	char *p1, *p2, *p3;
	int carry = 0;
	
	strcpy(pstr1, str1);
	strcpy(pstr2, str2);
	
	strrev(pstr1);
	strrev(pstr2);
	
	p1 = pstr1;
	p2 = pstr2;
	p3 = result;
	
	while(*p1 || *p2 || carry)
	{
		*p3 = carry;
		if (*p1)
			*p3 += *p1++ - '0';
		if (*p2)
			*p3 += *p2++ - '0';
		carry = *p3 / 10;
		*p3 = *p3 % 10 + '0';
		p3++;
	}
	
	*p3 = '\0';
	strrev(result);
	
	free(pstr1);
	free(pstr2);
	
	return result;
}

int main() {
	char result[100];
  	puts(add("123", "2340000000000000000000000", result));
  	return 0;
}
