#include <stdio.h>
#include <string.h>
#include <ctype.h>

void str_insert(char org[], int pos, const char str[]) {
	char temp[1000];
	int len = strlen(org);
	if (len < pos)
		return;

	strcpy(temp, org + pos);
	strcpy((org + pos), str);
	strcat(org, temp);
}

int main() {
	char str[1000], insert[1000];
	int n;
	gets(str);
	scanf("%d\n", &n);
	gets(insert);

	str_insert(str, n, insert);

	puts(str);
	return 0;
}
