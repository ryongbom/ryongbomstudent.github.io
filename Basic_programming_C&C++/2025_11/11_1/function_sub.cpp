#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char *sub(const char *num1, const char *num2, char *result)
{
	char *pnum1 = (char*)malloc(strlen(num1) + 1);
	char *pnum2 = (char*)malloc(strlen(num2) + 1);
	char *p1, *p2, *p3;
	strcpy(pnum1, num1);
	strcpy(pnum2, num2);
	strrev(pnum1);
	strrev(pnum2);
	p1 = pnum1;
	p2 = pnum2;
	p3 = result;
	int carry = 0;
	
	while(*p1) {
		*p3 = *p1++ - '0' + carry;
		if (*p2)
			*p3 -= *p2++ - '0';
		if (*p3 < 0) {
			carry = -1;
			*p3 += 10;	
		}
		else 
			carry = 0;
		*p3++ += '0';
	}
	
	*p3 = 0;
	*p3--;
	while(*p3 == '0') *p3-- = 0;
	
	strrev(result);
	free(pnum1);
	free(pnum2);
	return result;
}

int main()
{
	char result[100];
	puts(sub("2340000000000000000000000", "12", result));
  	puts(sub("2340000000000000000000002", "2340000000000000000000000", result));
  	return 0;
} 
