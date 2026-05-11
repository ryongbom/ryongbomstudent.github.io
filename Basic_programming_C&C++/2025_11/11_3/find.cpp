#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char a[1000][1000];
	int count, len, i, j;
	scanf("%d", &count);
	scanf("%d", &len);
	for (i = 0; i < count; i++)
		scanf("%s", a[i]);
	
	char result[1000][1000];
	
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < len; j++)
		{
			if(a[i][j] == '*')
				result[i][j] = '*';
			else
			{
				int k, u;
				int carry = 0;
				for(k = i - 1; k <= i + 1; k++)
				{
					for (u = j - 1; u <= j + 1; u++)
					{
						if (a[k][u] == '*')
							carry++;
					}
				}
				result[i][j] = carry + '0';
			} 
		}
	}
	
	for (i = 0; i < count; i++)
		printf("%s\n", result[i]);

	
	return 0;
}
