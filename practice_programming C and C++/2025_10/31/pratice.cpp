#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char str[1000];
	int num[1000] = {0};
	char cal[1000];
	int u = 0;
	gets(str);
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (isdigit(str[i]))
		{
			int count = 0;
			while (isdigit(str[i]))
			{
				count++;
				i++;
			}
			for (int j = i - count; j < i; j++)
			{
				int sum = str[j] - '0';
				for (int k = 1; k < count; k++)
				{
					sum *= 10;
				}
				num[i] += sum;
				count--;	
			}	
			cal[u++] = num[i];
			i = i - 1;
		}
		else
			cal[u++] = str[i];
	}
	for (u = 0; cal[u]; u++)
		printf("%d:%d\n", u, cal[u]);
	int result;
	if (cal[1] == '*')
		result = 0;
	else 
		result = cal[0];
	printf("%d\n", result);
	int product = 1; 
	for (u = 0; cal[u]; u++)
	{
		if (!isdigit(cal[u]))
		{
			if (cal[u] == '*')
			{
				int temp = u;
				while(cal[temp] == '*')
				{
					product *= cal[temp - 1];
					temp += 2;
				}	
				product *= cal[temp - 1];
				if (cal[u - 2] == '-')
					result -= product;
				else
					result += product;
				u = temp - 1;
			}
			else if (cal[u] == '+' && cal[u + 2] != '*')
			result += cal[u + 1];
			else if (cal[u] == '-' && cal[u + 2] != '*')
			result -= cal[u + 1];
		}	
	}
	printf("%d", result);
	return 0;
}
