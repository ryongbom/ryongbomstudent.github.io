#include <stdio.h>
#include <string.h>

#define NAME_LEN 20
#define COUNT 5

struct student {
	int no;
	char name[NAME_LEN];
	float score;
};

int main() {
	int i, j;
	struct student data[COUNT], temp;
	
	for (i = 0; i < COUNT; i++)
		scanf("%d%s%f", &data[i].no, data[i].name, &data[i].score);
		
	for (i = 0; i < COUNT; i++)
		for (j = i + 1; j < COUNT; j++)
			if (data[i].score < data[i].score)
				temp = data[i]; data[i] = data[j]; data[j] = temp;
				
	for (i = 0; i < COUNT; i++)
		printf("%d %s %.2f\n", data[i].no, data[i].name, data[i].score);
		
	return 0;
}
