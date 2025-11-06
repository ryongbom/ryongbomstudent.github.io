#include <stdio.h>
#define NAME_LEN 20

typedef struct {
	char name[NAME_LEN];
	int num_year;
	int num_class;
	float score[3];
}Student;

int main() {
	int n, i, j;
	Student date[100];
	
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%s%d-%d", date[i].name, &date[i].num_year, &date[i].num_class);
		for (j = 0; j < 3; j++)
		{
			scanf("%f", &date[i].score[j]);
		}
	}
	for (i = 0; i < 3; i++) {
		float sum = 0;
		for (j = 0; j < n; j++) {
			sum += date[j].score[i];
		}
		printf("%.2f ", sum / n);
	}
	return 0;
}
