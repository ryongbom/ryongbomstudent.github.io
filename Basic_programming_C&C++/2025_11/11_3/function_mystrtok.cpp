// ÊÎ½£ËÍ°¡²÷ strtok°¯ËË »ÕË© ÂÜºã´ª ³­°¡ °éÂï·ÃÃÕÊİ²÷°¡? Â×²÷ ÆÁ°¡ ÄÖ Êò°ÃËË³Ş. 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *pstr; // ¹¤ÂÚ¶ë¼è¶ì Ì¡¾·¶¦ ¸ó±ãÃÍ¼Ñ±¨ Ì¡Â×ÊŞ ¸ÔËæ ÁäËÍÀ¾º¼¼³ 

char *mystrtok(char *str, char *delim)
{
	char *result = 0;
	
	if (str) pstr = str; // ½åËÁÂÜºã´®¶²»¤Ëæ²÷ str¶¦ ²ÄÊÌ¼ÑÊİ±¨ÆÁ·ÍËæ pstr°¡ strµá ½ó±¨Ãù´óÊŞ »¤»õÂÙ³Ş. ³ŞËÁ ºåÃû¹¢À¾²÷ NULLË¾ ²ÄÊÌ¼Ñ·àµá ··µß·ÍËË »¤»õ´ó¼èÊ±°Ö ¼­ºåÃûÌ© ¶ë¼è¶ìÌ¡¾·³ŞËÁ¹¢À¾ »¤»õÂÙ³Ş. 
	
	while (*pstr && strchr(delim, *pstr))
	{
		*pstr = 0;
		pstr++;
	}
	if (!*pstr) return NULL;
	
	result = pstr;
	
	while (*pstr && !strchr(delim, *pstr))
		pstr++;
	
	if (*pstr)
		*pstr++ = 0;
	
	return result;
}

int main()
{
	char str[] = "C, programming. ", seps[] = " .,";
	char *p;
	
	p = mystrtok(str, seps);
	puts(p);
	p = mystrtok(NULL, seps);
	puts(p);
	p = mystrtok(NULL, seps);
	printf("%d", p == NULL);
	
	return 0;
} 
