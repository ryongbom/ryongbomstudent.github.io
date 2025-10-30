#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str1[100];
	char str2[100];
	int i, j;
	
	gets(str1);
	gets(str2);
	
	int max_match = 0;
	int n = 0;
	int temp = 0;
	for(i = 0; i < strlen(str1); i++)
	{	
		for (j = 0; j < strlen(str2); j++)
		{
			if (str2[j] == str1[i])
			{
				int match_count = 0;
				int pos1 = i;
				int pos2 = j;
				
				while(pos1 < strlen(str1) && pos2 < strlen(str2) && str1[pos1] == str2[pos2]){
					match_count++;
					pos1++;
					pos2++;
				}
				
				if (match_count > max_match)
				{
					max_match = match_count;
				}
			}	
		}
		if (max_match > n)
		{
			n = max_match;
			temp = i;
		}
	}

	for (i = n; i < n + temp; i++)
		printf("%c", str1[i]);

	return 0;
}
