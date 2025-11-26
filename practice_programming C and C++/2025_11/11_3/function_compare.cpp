// ÁäËÍÀ¾°¡ °Î¿¸ ÃÉ´Ç ±¶²ËË¼ Ê­³£¼è¶í »ÕË©±¶²Ë´ª Ê­³£³Ş. 
// 2025²É 11Ì» 3ËÎ 8»¤ 2¹¤ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare(char *str1, char *str2)
{
	if (str1[0] == '-')
	{
		if (str2[0] == '-')
			return -compare(str1 + 1, str2 + 1);
		else 
			return -1;
	}
	else
	{
		if (str2[0] == '-')
			return 1;
		if (strlen(str1) != strlen(str2))
			return strlen(str1) - strlen(str2);
			
			return strcmp(str1, str2);
	}
}

int main()
{
	char a[99][101], temp[101]; // 2½ÓÌº¹ÉµÛË¾ ÌÁ ¸ÊÊ­´ÉÊîËº·° ÊÌÅø±Â ÃüË¦ÃÕ²÷¼è ¶®ÃÍ°¡ ¼³ÃúÃÅ Ê¯Ê÷ 
	int n;
	scanf("%d", &n);
	
	int i, j;
	for (i = 0; i < n; i++) 
		scanf("%s", a[i]);
	
	for (i = 0; i < n; i++) // 2½ÓÌº¹ÉµÛË¾ ÊÌÅø±Â ±¨°äËØ±Â swapÃÕ²÷¼è? 
	{
		for (j = i + 1; j < n; j++) // j¶¦ ÊÌÅø±Â ÃüË¦? 
		{
			if (compare(a[i], a[j]) > 0)
			{
				strcpy(temp, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], temp);	
			}
		}
		puts(a[i]);
	}
	
	return 0;
}
