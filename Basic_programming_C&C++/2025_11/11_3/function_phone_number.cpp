#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char a[8][5] = { {'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}, {'J', 'K', 'L'}, {'M', 'N', 'O'},
	 {'P', 'Q', 'R', 'S'}, {'T', 'U', 'V'}, {'W', 'X', 'Y', 'Z'} };
	int i = 0, j = 0;
	int n;
	scanf("%d", &n);
	char alpha[1000][1000];
	for (i = 0; i < n; i++)
		scanf("%s", alpha[i]);
		
	int temp = -1;
	for (i = 0; i < n; i++)
	{
		int len = strlen(alpha[i]);
		for (j = 0; j < len; j++)
		{
			//printf("%c\n", alpha[i][j]);
			int k, u;
			for (k = 0; k < 8; k++)
			{
				for (u = 0; u < 5; u++)
				{
					if (a[k][u] == alpha[i][j])
					{
						//printf("%d:%d\n", k, u);
						if(k == temp)
							printf("0");
						int count = u + 1; 
						while (count > 0)
						{
							printf("%d", k + 2);
							count--;
						}
						temp = k;
					}
				}
			}
		}
	printf("\n");
	}
	return 0;
} 
