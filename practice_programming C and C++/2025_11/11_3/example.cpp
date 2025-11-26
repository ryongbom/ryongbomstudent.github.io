 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 
 #define MAX_LEN 1000
 #define WORD_LEN 30
 #define WORD_COUNT 100
 
 int main() {
	char s[MAX_LEN], *p, seps[] = " ,.:!?";
	char words[WORD_COUNT][WORD_LEN], temp[WORD_LEN]; // 2차원 배렬 여기에서는 길이가 30인 배렬이 100개 있다. 
	int count = 0, i, j;
  	gets(s);
  	
  	p = strtok(s, seps);
  	while(p) {
  		strcpy(words[count++], p);
  		p = strtok(NULL, seps);
	}
	
	for (i = 0; i < count; i++)
		for (j = i + 1; j < count; j++) {
			if (strcmp(words[i], words[j]) > 0) {
				strcpy(temp, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], temp);
			}
		}
		
	for (i = 0; i < count; i++)
		puts(words[i]);
  	
  	return 0;
}
