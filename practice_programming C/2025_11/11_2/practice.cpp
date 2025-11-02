#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char num_16[] = "123A";
	int len = strlen(num_16);
	char *p = (char*)malloc(len + 1);
	if (p == NULL) {
        return 1;
    }
	strcpy(p, num_16);
	int num_10 = 0;
//	int temp = 1;
//	int num = 0;
	int n = 16;
	char *current = p;
	
/*	while (*current)
	{
		if (isdigit(*current))
			num = *current - '0';
		else 
			num = toupper(*current) - 'A' + 10;
		len--;
		int carry = len;
		temp = 1;
		
		while(carry > 0)
		{
			temp *= n;
			carry--;
		}
		num_10 += (num * temp);
		current++;
	}
*/
	 while (*current) {
        int digit;
        char c = toupper(*current);
        
        if (isdigit(c))
            digit = c - '0';
        else
            digit = c - 'A' + 10;
        
        num_10 = num_10 * 16 + digit;
        current++;
    }
    
	printf("%d", num_10);
	free(p);
	return 0;
}
