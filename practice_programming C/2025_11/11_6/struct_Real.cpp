#include <stdio.h>

struct Real {
	long long a;
	long long b;
};

void fucPrint(struct Real c, int n) {
	long long b[1000];
	int count = 0;
	
	long long temp = c.b, index = 0;
	while(temp) {
		b[index] = temp % 10;
		temp /= 10;
		index++;
	}

	printf("%d.", c.a);
		
	for (int i = index - 1; i >= index - n; i--) {
		printf("%d", b[i]);
	}
}

int main() {
	struct Real f;
	int n;
	scanf("%d.%d", &f.a, &f.b);
	scanf("%d", &n);
	fucPrint(f, n);
	return 0;	
}
