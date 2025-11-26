#include <stdio.h>
#include <string.h>
#include <ctype.h>
int const Max_array = 1000;

int main(){
	char array[Max_array];
	char array1[Max_array];
	char array2[Max_array];
	int count[Max_array] = {0};
	
	gets(array);
	
	int len = strlen(array);
	
	for (int i = 1; i < len; i++)
	{
		if (array[i - 1] == array[i + 1])
			count[i] = 1;
	}
	
	int count_max = 0;
	int i_temp;
	for (int i = len / 2; i < len; i++)
	{
		if(count[i])
		{
			int j = i;
			int k = i;
			while(j < len)
			{
				if(array[j] != array[k])
				{
					count[i] = 0;
					break;
				}
				count[i]++;
				j++;
				k--;	
			}
			if (count[i] > count_max)
			{
				count_max = count[i];
				i_temp = i;
			}
		}	
	}
	count_max -= 2;
//	printf("%d:%d", i_temp + 1, count_max);
	int j = 0;
	for (int i = i_temp - count_max - 1; i >= 0; i--)
		array1[j++] = array[i];
	array1[j] = '\0';
	puts(strcat(array, array1));
	puts(array1);
	return 0; 
}

//int main() {
//	char str[1000], rev[1000];
//	int i, len;
//	
//	gets(str);
//	strcpy(rev, str);
//	strrev(rev);
//	
//	for (len = strlen(str); len >= 0; len--) {
//		i = strlen(str) - len;
//		if (strncmp(str + i, rev, len) == 0) {
//			printf("%s%s\n", str, rev + len);
//			puts(rev + len);
//			return 0;
//		}
//	}
//
//	return 0;
//}
