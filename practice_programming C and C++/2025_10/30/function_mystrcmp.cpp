#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mystrcmp(const char *str1, const char *str2)
{
	while(*str1 || *str2)
	{
		if(*str1++ > *str2++)
		{	
			return 1;
			break;
		}
		else if(*str1++ < *str2++)
		{	
			return -1;
			break;
		}
		str1++;
		str2++;
	}
	return 0;
}

int main() {
  	printf("%d ", mystrcmp("appear", "apple"));
  	printf("%d ", mystrcmp("apple", "apple"));
  	printf("%d", mystrcmp("apple", "appear"));
  	return 0;
}
