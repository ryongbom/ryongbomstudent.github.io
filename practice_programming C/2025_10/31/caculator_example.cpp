#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
	char str[1000], op;
	int num, result, term;
	
	result = 0;
	term = 1;
	num = 0;
	
	gets(str);
	
	op = '+';
	
	for (int i = 0; ; i++)
	{
		if (isdigit(str[i]))
			num = num * 10 + str[i] - '0';
		else if (str[i] == ' ' || str[i] == '\t')
			continue;
		else
		{
			term *= num;
			if (str[i] == '+' || str[i] == '-' || str[i] == 0)
			{
				if(op == '+')
					result += term;
				else 
					result -= term;
				op = str[i];
				term = 1;
				
				if (str[i] == 0)
				{
					printf("%d", result);
					break;
				}
			}
			num = 0;
		}
	}
	return 0;
}
