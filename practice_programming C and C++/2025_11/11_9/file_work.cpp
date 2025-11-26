#include <stdio.h>

int main () {
	FILE *fp;
	int sum = 0, n;
	fp = fopen("D/a.txt", "r");
	if (fp = NULL) {
		printf("ÃùËÎÊâ±¨ÊïË±\n");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &n);
		sum += n;
	}
	fclose(fp);
	
	fp = fopen("b.txt", "w");
	if (fp = NULL) {
		printf("ÃäËÎÊâ±¨ÊïË±\n");
		return 0;
	}
	fprintf(fp, "sum = %d", sum);
	fclose(fp);
	return 0;
}
