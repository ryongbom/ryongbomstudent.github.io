#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sort(char *str, int (*cmp)(char, char)) {
	int i, j;
	char temp;
	for (i = 0; str[i]; i++)
		for (j = i + 1; str[j]; j++)
			if (cmp(str[i], str[j]) > 0)
				temp = str[i], str[i] = str[j], str[j] = temp;
}

int ascending(char a, char b) {
	if (toupper(a) == toupper(b)) // °¯Ë¼ ·Í»ôËÎÆÁ ´İ·Í»ô ºÏ·Í»ô°é¹¤ 
		return a - b;
	else
		return toupper(a) - toupper(b);
}

int descending(char a, char b) {
	if (toupper(a) == toupper(b))
		return b - a;
	else
		return toupper(b) - toupper(a);
}

int main(int argc, char *argv[]) {
	if (argc < 3) {
		puts("Invalid arguments.");
		return 0;
	}
	
	if (!strcmp(argv[2], "asc"))
		sort(argv[1], ascending);
	else if (!strcmp(argv[2], "desc"))
		sort(argv[1], descending);
		
	puts(argv[1]);
	
  	return 0;
} 
